/////////////////////////////////////////////////////////////////////
//
// Name: Landon Burns
// Date: 4/19/2022
// Class: CSCI 1370.04
// Semester: Spring 2022
// CSCI 1370 Instructor: Gustavo Dietrich
//
// Program Description: This program takes takes and displays the names of candidates and their votes from a reset list and calculates their percentage of votes. It also calculates and displays the winner.
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int sumList(const int list[], int size);
int indexOfMax(const int list[], int size);
// This function gets the results from the file and returns them in the corresponding
void getElectionData(ifstream & iFile, string candidates[], int ballots[], int & count);
void printResults(const string candidates[], const int ballots[], int count, int totalBallots);
const int NUM_CANDIDATES = 10; // The number of candidates

int main()
{
	ifstream inFile;
	string names[NUM_CANDIDATES];	// The names of the candidates
	int votes[NUM_CANDIDATES];		// The number of votes received by each candidate
	int totalVotes;					// The total number of votes received by all candidates
	int max;						// number of candidates processed

	inFile.open("votingresults.txt");
	if (!inFile)
	{
		cout << "File not found!" << endl << endl;
		return 1;
	}
	
    ///////////////////////////////
    // Start your code here


    // Get the candidates' names and number of votes each received
    // Assume the user enters valid input (just call the getElectionData() function)
getElectionData(inFile, names, votes, max);
	

    // Calculate the total number of votes received by all candidates
    // (call the sumList() function)
totalVotes = sumList(votes, max);

    // Print each candidate's name, the number of votes she received,
    // and the percent of votes the candidate received
	// (just call the printResults() function)

printResults(names, votes, max, totalVotes);

    system("pause");

	
    // End of your code in the main function
    // Don't forget to complete the functions below
    ///////////////////////////////

    return 0;
}

//************************  Function definitions  *************************


//
// Returns the sum of the numbers in the given array

int sumList(const int list[], int size)
{

    int sum = 0;

    for (int i = 0; i < size; i++){
        sum += list[i];

      }

    return sum;
  }

// Returns the INDEX of the largest value in the given array.
// IMPORTANT: it does not return the largest value, but the INDEX of the element where it is)

int indexOfMax(const int list[], int size)
{

    int maxin = 0;


    for (int i = 0; i < size; i++)
    {

        if (list[i] > list[maxin])

            maxin = i;
    }

    return maxin;
}

// Gets the names of the candidates and the votes they got from the file and returns
// them in the corresponding arrays. It also returns the number of rows in the file that
// were processed Makes sure it never goes over the array capacity when loading the data
// in the arrays

void getElectionData(ifstream &iFile, string candidates[], int ballots[], int &count)
{

    count = 0;
    while (iFile >> candidates[count] >> ballots[count])
    {
        count++;
    }
}

// Receives the candidates names and the quantity of votes they got, the number of elements
// in the arrays to be processed, and the total number of votes so they can be displayed as
// shown in the file with the problem statement
// Must call the indexOfMax function() to find the array index of the candidate with the
// largest number of votes

void printResults(const string candidates[], const int ballots[], int count, int totalBallots){

cout << fixed << left << setprecision(2);

cout << setw(15) << "Candidate" << setw(15) << "Num Votes" << setw(15) << "% of Votes" << endl;

    for (int i = 0; i < count; i++)
    {

double percent = ((double)ballots[i] / (double)totalBallots) * 100.0;

cout << setw(15) << candidates[i] << setw(15) << ballots[i] << setw(15) << percent << endl;
    }
    cout << endl;

    int winner = indexOfMax(ballots, count);

    cout << "The winner is: " << candidates[winner] << endl;
}