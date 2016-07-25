#include <iostream>
#include <string>
#include <vector>

using namespace std;


void leftSlide(vector< vector<int> >& puzzle)
{
    //the pointer
    int position;

    //Finds the 0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(puzzle.at(i).at(j) == 0)
            {
                position = j;
                if(position != 3)
                {
                    while(position < 3)
                    {
                        puzzle.at(i).at(position) = puzzle.at(i).at(position + 1);
                        position++;
                    }
                    puzzle.at(i).at(position) = 0;
                }
            }
        }
    }
}


void rightSlide(vector< vector<int> >& puzzle)
{
    int position;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(puzzle.at(i).at(j) == 0)
            {
                position = j;
                if(position != 0)
                {
                    while(position > 0)
                    {
                        puzzle.at(i).at(position) = puzzle.at(i).at(position - 1);
                        position--;
                    }
                    puzzle.at(i).at(position) = 0;
                }
            }
        }
    }
}



void upSlide(vector< vector<int> >& puzzle)
{
    int position;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(puzzle.at(i).at(j) == 0)
            {
                position = i;
                if(position != 3)
                {
                    while(position < 3)
                    {
                        puzzle.at(position).at(j) = puzzle.at(position + 1).at(j);
                        position++;
                    }
                    puzzle.at(position).at(j) = 0;
                }
            }
        }
    }
}

void downSlide(vector< vector<int> >& puzzle)
{
    int position;
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
        {
            if(puzzle.at(i).at(j) == 0)
            {
                position = i;
                if(position != 0)
                {
                    while(position > 0)
                    {
                        puzzle.at(position).at(j) = puzzle.at(position - 1).at(j);
                        position--;
                    }
                    puzzle.at(position).at(j) = 0;
                }
            }
        }
    }
}


void display(vector< vector<int> >& puzzle)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << puzzle.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    //Setting up puzzle
    int num = 1;
    vector< vector<int> > puzzle(4, vector<int>(4));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(num < 16)
            {
                puzzle.at(i).at(j) = num;
                num++;
            }
            else
            {
                num = 0;
                puzzle.at(i).at(j) = num;
            }
        }
    }
    //displaying puzzle
    display(puzzle);


    //Choices
    string choice = "";
    string YorN = "";
    do
    {
        cout << "left, right, up, or down?" << endl;
        cin >> choice;
        cout << endl;

        if(choice == "left")
        {
            leftSlide(puzzle);
        }
        else if(choice == "right")
        {
            rightSlide(puzzle);
        }
        else if(choice == "up")
        {
            upSlide(puzzle);
        }
        else if(choice == "down")
        {
            downSlide(puzzle);
        }
        else if(choice == "quit" || choice == "stop")
        {
            break;
        }

        else
        {
            cout << "Not valid." << endl;
        }
        display(puzzle);

    }
    while(true);

    return 0;
}
