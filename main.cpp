#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream stuff;
    stuff.open("hamlet.txt.rft");

    vector<string> words;
    if (stuff.is_open())
    {
        string word;
        while (stuff >> word)
        {
            words.push_back(word);
        }
        stuff.close();
    }
    else
    {
        cerr << "Unable to open file hamlet.txt.rft" << endl;
        return 1;
    }

    while (true)
    {
        cout << "Enter a word to search for (or type 'exit' to quit): ";
        string in;
        cin >> in;

        if (in == "exit")
        {
            cout<< "Exiting the program." << endl;
            break;
        }

        int count = 0;
        for (const auto& w : words)
        {
            if (w == in)
            {
                count++;
            }
        }

        cout << "The word '" << in << "' appears " << count << " times in the text." << endl;
    }
    stuff.close();
    return 0;

}