#include <iostream>
using namespace std;

template <typename T>
void Dump(T N, int r)
{
    T mask;
    switch (r)
    {
        case 2:
        {
            int size(8 * sizeof(T) - 1);
            switch (sizeof(T))
            {

                case 2 :
                    mask = 040000;
                    break;

                case 4 :
                    mask = 010000000000;
                    break;
                case 1 :
                    mask = 0100;
                    break;
            }
            cout << (N < 0 ? '1' : '0');
            for (int i = 0; i < size; ++i)
            {
                cout << (N & mask ? '1' : '0');
                mask >>= 1;
            }
            cout << endl;
            break;
        }
        case 8:
        {
            int size((8 * sizeof(T)) / 3);
            int base(3 * ((8 * sizeof(T) / 3) - 1));
            switch (sizeof(T))
            {
                case 1 :
                    mask = 070;
                    cout << char(((N >> 6) & 03) + 48);
                    break;

                case 2 :
                    mask = 070000;
                    cout << (N < 0 ? '1' : '0');
                    break;

                case 4 :
                    mask = 07000000000;
                    cout << char(((N >> 30) & 03) + 48);
                    break;
            }
            for (int i = 0; i < size; ++i, mask >>= 3)
                cout << char(((N & mask) >> base - i * 3) + 48);
            cout << endl;
            break;
        }
        case 16:
        {
            int size(2 * sizeof(T) - 1);
            int base(8 * (sizeof(T) - 1));
            int digit((N >> (8 * sizeof(T) - 4)) & 0xf);
            switch (sizeof(T))
            {
                case 1 :
                    mask = 0xf;
                    break;

                case 2 :
                    mask = 0xf00;
                    break;

                case 4 :
                    mask = 0xf000000;
                    break;
            }
            cout << (digit > 9 ? char(digit + 87) : char(digit + 48));
            for (int i = 0; i < size; ++i, mask >>= 4)
            {
                digit = (N & mask) >> base - i * 4;
                cout << (digit > 9 ? char(digit + 87) : char(digit + 48));
            }
            cout << endl;
            break;
        }
        default:
            cout <<  "Wrong  value. '" << r << endl;
            break;
    }
}

int main()
{
    int n = 0, r = 0;
    short int shortInt = 0;
    char charValue = 0;
    int inPutValue = 0;
    do
    {
        cout << "0 for int\n1 for short int\n2 for char\nType: ";
        cin >> inPutValue;
        if (inPutValue == 0 || inPutValue == 1 || inPutValue == 2) break;
    }
    while (true);
    do
    {
        cout << "Number: ";
        switch (inPutValue)
        {
            case 0:
                cin >> n;
                break;
            case 1:
                cin >> shortInt;
                break;
            case 2:
                cin >> shortInt;
                break;
            default:
                cout << "Wrong inPut." << endl;
                break;
        }
        if (cin.good())
        {
            cout << "Radix: ";
            cin >> r;
            if (cin.good())
            {
                break;
            }
        }
        else
        {
            cout << "Invalid data!\n";
            cin.clear();
            while(cin.get() != '\n');
        }
    }
    while(true);
    switch(inPutValue)
    {
        case 0:
            Dump<int>(n, r);
            break;
        case 1:
            Dump<short int>(shortInt, r);
            break;
        case 2:
            Dump<char>(charValue, r);
            break;
        default:
            cout << "Wrong inPutValue." << endl;
            break;
    }
    return 0;
}