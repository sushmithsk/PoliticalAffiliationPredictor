/*This program gives the user a questionaire that determines their party affiliation.
It then saves their answers and party affiliation to a database file called 'answer_database.txt'.*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "question_bank.h"

using namespace std;

//Declaring all the functions
bool calculate_score(vector<string> &answers);
bool clearWinner(int a, int b, int c, int d, vector<string> &answers);
void update_weights(vector<weightedQuestion> qna);

//Creating a struct that will be used to update weights
struct PersonData {
    string name;
    vector<string> answers;
};

int main(){
  //Declaring a vector to hold the answers, a string for the participant's name, a counter to see  how many questions have been asked, and a boolean to check if we have made a guess
  vector<string> answers;
  vector<vector<float>> scores;
  string name;
  string answer;
  bool finish;
  int counter = 0;
  bool keep_going = true;

  update_weights();

  while (keep_going) {//Get the name of the participant to add to the output file
    cout << "Enter your name: " << endl;
    getline(cin, name);
    answers.push_back(name);

    //Loop over the questions and get the answers
    // Iterate through each question and record the user's answers

    for (int i = 0; i < qAndScores.size(); i++){
      cout << qAndScores[i].question << endl;
      cout << "Please enter your answer (\"A\" \"B\" or \"C\"): ";
      cin >> answer;
      //Convert the answer to uppercase to prevent errors
      transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
      scores = qAndScores[i].returnScores(answer);
      answers.push_back(answer);
      counter++;
      if (counter > 10){
        finish = calculate_score(answers);
        if (finish){
          break;
        }
      } 
    }
    //Update the document to add in the answers 
    ofstream
      outfile("answer_database.txt", ios::app);
      if (outfile.is_open()) {
        for (const auto& answer : answers) {
          outfile << answer << endl;
        }
        outfile.close();

        cout << endl << "Answers successfully added to the database" << endl;
      } else {
        cout << "Error: Unable to open the database file for writing" << endl;
      }
    //Ask the user if they want to continue
    cout << "Do you want to continue? (y/n): ";
    cin >> answer;
    //Convert the answer to lowercase to prevent errors
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if (answer == "n"){
      keep_going = false;
      }
    }
  };

bool calculate_score(vector<string> &answers){
  //Declaring all variables
  int scoreA = 0, scoreB = 0, scoreC = 0, scoreD = 0;
  int questions_answered = answers.size();

  //Run a for loop to calculate the number of answers that lean towards each of the four parties.
  for (int i = 0; i < questions_answered; i++){
    if (answers[i] == "A"){
      scoreA++;
    }else if (answers[i]== "B"){
      scoreB++;
    }else if (answers[i] == "C"){
      scoreC++;
    }else if (answers[i] == "D"){
      scoreD++;
    }
  }
  return clearWinner(scoreA, scoreB, scoreC, scoreD, answers);

};


bool clearWinner(int scoreA, int scoreB, int scoreC, int scoreD, vector<string> &answers){
  //Declaring variables
  string response;
  string party_affiliation;

  //If one of the scores is greater than the sum of the rest, guess that the user leans towards that party.
  if (scoreA > (scoreB+scoreC+scoreD)){
    cout << "Are you a democrat? Type 'y' or 'n':" << endl;
    cin >> response;
    //Turn response into a lowercase entry to prevent errors
    transform(response.begin(), response.end(), response.begin(), ::tolower);
    if (response == "y"){
      cout<< "We guessed right!" << endl;
      party_affiliation = "Democrat";
    } else{
      cout<< "We were wrong. Please enter your party affiliation:" << endl;
      cin.ignore();
      getline(cin, party_affiliation);
    } return true;
    } else if (scoreB > (scoreA + scoreC + scoreD)){
      cout << "Are you a republican? Type 'y' or 'n':" << endl;
      cin >> response;
      if (response == "y"){
        cout<< "We guessed right!" << endl;
        party_affiliation = "Republican";
      } else{
        cout<< "We were wrong. Please enter your party affiliation:"<<endl;
        cin.ignore();
        getline(cin, party_affiliation);
    } return true;
  } else if (scoreC > (scoreA + scoreB + scoreD)){
    cout << "Are you a libertarian? Type 'y' or 'n':" << endl;
    cin >> response;
    if (response == "y"){
      cout<< "We guessed right!" << endl;
      party_affiliation = "Libertarian";
    } else{
      cout<< "We were wrong. Please enter your party affiliation:"<<endl;
      cin.ignore();
      getline(cin, party_affiliation);
      }return true;
    }else if (scoreD > (scoreA + scoreB + scoreC)){
      cout << "Are you a green party supporter? Type 'y' or 'n':" << endl;
      cin >> response;
      if (response == "y"){
        cout<< "We guessed right!" << endl;
        party_affiliation = "Green Party";
      }else{
        cout<< "We were wrong. Please enter your party affiliation:"<<endl;
        cin.ignore();
        getline(cin, party_affiliation);
      }return true;
  }

  //If all 29 questions have been answered, guess whichever is the most popular party and return true.
  if (answers.size() == 29){
    int maxScore = max(max(scoreA, scoreB), max(scoreC, scoreD));
    if ( maxScore == scoreA){
      cout << "Are you a democrat? Type 'y' or 'n':" << endl;
      cin >> response;
      if (response == "y"){
        cout<< "We guessed right!" << endl;
        party_affiliation = "Democrat";
    } else {
        cout<< "We were wrong. Please enter your party affiliation:"<<endl;
        cin.ignore();
        getline(cin, party_affiliation);
      }
  }else if (maxScore == scoreB){
      cout << "Are you a republican? Type 'y' or 'n':" << endl;
    if (response == "y"){
      cout<< "We guessed right!" << endl;
      party_affiliation = "Republican";
  }else{
        cout<< "We were wrong. Please enter your party affiliation:"<<endl;
        cin.ignore();
        getline(cin, party_affiliation);
    }
  }else if (maxScore == scoreC){
      cout << "Are you a libertarian? Type 'y' or 'n':" << endl;
      cin >> response;
      if (response == "y"){
        cout<< "We guessed right!" << endl;
        party_affiliation = "Libertarian";
      }else{
          cout<< "We were wrong. Please enter your party affiliation:"<<endl;
          cin.ignore();
          getline(cin, party_affiliation);
      }
  } else if (maxScore == scoreD){
      cout << "Are you a green party supporter? Type 'y' or 'n':" << endl;
      cin >> response;
      if (response == "y"){
        cout<< "We guessed right!" << endl;
        party_affiliation = "Green Party";
      }else{
          cout<< "We were wrong. Please enter your party affiliation:"<<endl;
          cin.ignore();
          getline(cin, party_affiliation);
      }
  }
  answers.push_back(party_affiliation);
  return true;
  }
return false;
};

vector<PersonData> readDataFromFile(const string& filename) {
      vector<PersonData> data;
      ifstream infile(filename);

      if (infile.is_open()) {
          string line;

          while (getline(infile, line)) {
              // Use a stringstream to parse the line
              stringstream ss(line);
              // Read the name
              string name;
              ss >> name;
              // Read the answers
              vector<string> answers;
              string answer;
              while (ss >> answer) {
                  answers.push_back(answer);
              }
              // Create a PersonData object and add it to the vector
              data.push_back({name, answers});
          }
          infile.close();
      } else {
          cout << "Error: Unable to open the file " << filename << endl;
      }
      return data;
  };


void update_weights(vector<weightedQuestion> qAndScores){
  // Function to read a text file and create a vector of PersonData
  // Specify the filename
  vector<string> filenames = {"democrat.txt", "republican.txt", "libertarian.txt", "green_party.txt"};


  for (int i; i< filenames.size(); i++) {
      int counter = 0;
      // Read data from the file
    vector<PersonData> personData = readDataFromFile(filenames[i]);

    // Loop through each PersonData object and update the weights
    for (const auto& person : personData) {
        for (const auto& answer : person.answers) {
            if (answer == "A") {
                qAndScores[counter].weights[0] += 0.5;
            } else if (answer == "B") {
                qAndScores[counter].weights[1] += 0.5;
            } else if (answer == "C") {
                qAndScores[counter].weights[2] += 0.5;
            } else if (answer == "D") {
                qAndScores[counter].weights[3] += 0.5;
            }

            counter++;
        }
        cout << endl;
    }
  }


};