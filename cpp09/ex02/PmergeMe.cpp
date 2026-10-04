#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/time.h>
#include <vector>
#include <limits>

static long get_time_usec();

template <typename C>
static void merge_insertion_indices(const C &arr, std::vector<int> &indices)
{
    size_t n = indices.size();
    if (n <= 1)
        return;

    std::vector<int> A_orig;
    A_orig.reserve((n + 1) / 2);
    std::vector<int> B;
    B.reserve((n + 1) / 2);
    int extra = -1;
    bool has_extra = false;
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        int idx1 = indices[i];
        int idx2 = indices[i + 1];
        if (arr[idx1] < arr[idx2])
        {
            A_orig.push_back(idx2);
            B.push_back(idx1);
        }
        else
        {
            A_orig.push_back(idx1);
            B.push_back(idx2);
        }
    }
    if (n % 2 == 1)
    {
        extra = indices[n - 1];
        has_extra = true;
    }

    std::vector<int> A_sorted = A_orig;
    merge_insertion_indices<C>(arr, A_sorted);

    std::vector<int> result;
    result.reserve(n);
    for (size_t i = 0; i < A_sorted.size(); ++i)
        result.push_back(A_sorted[i]);

    std::vector<int> B_sorted;
    B_sorted.reserve(A_orig.size());
    for (size_t ai = 0; ai < A_sorted.size(); ++ai)
    {
        int a_idx = A_sorted[ai];
        for (size_t bi = 0; bi < A_orig.size(); ++bi)
        {
            if (A_orig[bi] == a_idx)
            {
                B_sorted.push_back(B[bi]);
                break;
            }
        }
    }

    std::vector<int> J;
    int m = (int)A_orig.size();
    for (int k = 1; k < 31; ++k)
    {
        long pow2 = 1L << k;
        long jk = (pow2 - ((k % 2 == 0) ? 1 : -1)) / 3;
        if (jk <= 0)
            continue;
        J.push_back((int)jk);
        if (jk >= m)
            break;
    }
    std::vector<int> order;
    if (m >= 1)
        order.push_back(1);
    int prev = 1;
    for (size_t ki = 0; ki < J.size(); ++ki)
    {
        int high = J[ki];
        if (high > m)
            high = m;
        for (int idx = high; idx >= prev + 1; --idx)
            order.push_back(idx);
        prev = high;
        if (prev >= m)
            break;
    }
    for (int idx = m; idx >= prev + 1; --idx)
        order.push_back(idx);

    for (size_t oi = 0; oi < order.size(); ++oi)
    {
        int one_based = order[oi];
        int a_idx = A_sorted[one_based - 1];
        int b_idx = B_sorted[one_based - 1];

        size_t pos = 0;
        bool found = false;
        for (size_t i = 0; i < result.size(); ++i)
        {
            if (result[i] == a_idx)
            {
                pos = i;
                found = true;
                break;
            }
        }
        if (!found)
            pos = result.size();

        size_t l = 0, r = pos;
        while (l < r)
        {
            size_t mid = l + (r - l) / 2;
            if (arr[b_idx] < arr[result[mid]])
                r = mid;
            else
                l = mid + 1;
        }
        result.insert(result.begin() + l, b_idx);
    }

    if (has_extra)
    {
        int b_idx = extra;
        size_t l = 0, r = result.size();
        while (l < r)
        {
            size_t mid = l + (r - l) / 2;
            if (arr[b_idx] < arr[result[mid]])
                r = mid;
            else
                l = mid + 1;
        }
        result.insert(result.begin() + l, b_idx);
    }

    indices = result;
}

template <typename C>
static void ford_johnson_sort(C &arr, long &time_usec)
{
    long start = get_time_usec();
    size_t n = arr.size();
    if (n == 0)
    {
        time_usec = 0;
        return;
    }
    std::vector<int> indices;
    indices.reserve(n);
    for (size_t i = 0; i < n; ++i)
        indices.push_back((int)i);

    merge_insertion_indices<C>(arr, indices);

    std::vector<int> out;
    out.reserve(n);
    for (size_t i = 0; i < indices.size(); ++i)
        out.push_back(arr[indices[i]]);
    for (size_t i = 0; i < n; ++i)
        arr[i] = out[i];
    long end = get_time_usec();
    time_usec = end - start;
}

PmergeMe::PmergeMe() : s(NULL) {}

PmergeMe::PmergeMe(const PmergeMe &p) : s(p.s) {}

PmergeMe::PmergeMe(char **av) : s(av) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &p)
{
    if (this != &p)
        s = p.s;
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string &str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    long long n = std::atoll(str.c_str());

    if (n < 0 || n > INT_MAX)
        return false;

    return true;
}

void PmergeMe::parseInput(int ac)
{
    for (int i = 1; i < ac; i++)
    {
        if (!isValidNumber(s[i]))
            throw std::logic_error("Error");
        int n = std::atoi(s[i]);
        v.push_back(n);
        d.push_back(n);
    }
}

std::vector<int> &PmergeMe::getVector()
{
    return v;
}

std::deque<int> &PmergeMe::getDeque()
{
    return d;
}

static long get_time_usec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void PmergeMe::sortVector()
{
    long duration = 0;
    ford_johnson_sort(v, duration);

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << duration << " us" << std::endl;
}

void PmergeMe::sortDeque()
{
    long duration = 0;
    ford_johnson_sort(d, duration);
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque  : " << duration << " us" << std::endl;
}