#include <iostream>
#include <cstring>

using namespace std;

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac < 2) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return 1;
    }
    for(i = 1;i < ac; i++)
    {
        for ( j = 0; j < strlen(av[i]); j++)
            cout << (char)toupper(av[i][j]);
        if (i < ac - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}