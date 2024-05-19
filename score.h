#ifndef score_h
#define score_h
#include <iostream>
#include <fstream>
using namespace std;
class Score
{
public:
    string filename;
    int scores;
    Score();
    int store_score(int score);
    int* Score_Display();
    int Score_Compare(int score);
};
Score::Score()
{
    filename = "highscores.txt";
}
int Score::store_score(int add_score)
{
    Score_Compare(add_score);
    return 0;
}
int* Score::Score_Display()
{
    int* high=new int[3];
    int i=0;
    fstream infile;
    infile.open(filename, ios::in);
    if (infile.is_open())
    {
        while (infile >> scores)
        {
            cout << scores << endl;
            high[i]=scores;
            i++;
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    infile.close();
    return high;
}
int Score::Score_Compare(int score)
{
    int count = 0;
    fstream infile;
    infile.open(filename, ios::in);
    int highest_score;
    ofstream temp;
    temp.open("temp.txt");
    bool flag=0;
    while (infile >> scores)
    {
        if(flag==1){
            count++;
        }
        else if (score > scores && flag==0)
        {
            count++;
            flag=1;
            continue;
        }
        else if (score <= scores)
        {
            count++;
        }
    }
    if(count==0){
        count++;
    }
    while(count<3){
        count++;
    }
    char *name = "highscores.txt";
    remove(name);
    rename("temp.txt", name);
    temp.close();

    count=0;
    fstream infile2;
    infile2.open(filename, ios::in);
    ofstream temp2;
    temp2.open("temp2.txt");
    while (infile2>>scores){
        if(count<3){
            count++;
        }
    }
    remove(name);
    rename("temp2.txt", name);
    temp2.close();
    return 0;
}

#endif