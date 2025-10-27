#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream stuff;
    stuff.open("hamlet.txt.rtf");

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
    bool b=true;
    while (b)
    {
        cout << "Enter a word to search for (or type 'exit' to quit): ";
        string in;
        cin >> in;

        if (in == "exit")
        {
            cout<< "Exiting the program." << endl;
            b=false;
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

    for(string w: words)
    {
        // Find most common word
        string mostW= words[0];
        for(string w: words)
        {
            int count1=0;
            int count2=0;
            for(string x: words)
            {
                if(w==x)
                {
                    count1++;
                }
                if(mostW==x)
                {
                    count2++;
                }
            }
            if(count1>count2)
            {
                mostW=w;
            }
        }
        cout<< "The most common word in Hamlet is: " << mostW << endl;


        // Count sentences
        int a=0;
        if (w==".")
        {
            a++;
        }
        cout<< "There are "<< a << " senctences in Hamlet." << endl;

        //Longest sentece
        string longest="";
        string current="";
        for(string w: words)
        {
            if(w!="." && w!="!" && w!="?")
            {
                current+= w + " ";
            }
            else
            {
                if(current.length()>longest.length())
                {
                    longest=current;
                }
                current="";
            }
            cout<< "The longest sentence in Hamlet is: " << longest << endl;
        }
    }


    stuff.close();
    return 0;

}