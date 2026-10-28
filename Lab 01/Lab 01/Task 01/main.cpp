#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int count_A = 0, count_G = 0, count_T = 0, count_C = 0;
    char ch;
    ifstream inFile;
    inFile.open("genome.txt");
    if (!inFile)
    {
        cout << "Error: could not open genome.txt" << endl;
    }
    while (inFile.get(ch))
    {
        switch (ch)
        {
        case 'A':
        {
            count_A++;
        }
        break;
        case 'G':
        {
            count_G++;
        }
        break;
        case 'T':
        {
            count_T++;
        }
        break;
        case 'C':
        {
            count_C++;
        }
        break;
        default:
            break;
        }
    }
    inFile.close();

    ofstream outFile;
    outFile.open("genomecount.txt");
    if (!outFile)
    {
        cout << "Error" << endl;
        return 1;
    }
    outFile << "A=" << count_A << " G=" << count_G << " T=" << count_T << " C=" << count_C << endl;
    outFile.close();
    cout << "A=" << count_A << " G=" << count_G << " T=" << count_T << " C=" << count_C << endl;
    return 0;
}
