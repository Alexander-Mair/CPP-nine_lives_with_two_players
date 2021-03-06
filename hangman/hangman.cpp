// hangman.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void guessRight(string);

int main() {
	string word, guessedWord, player1, player2;
	char guessedLetter=' ', option=' ';
	string hiddenWord;

	int lives=0;

	cout << "Please enter your name player 1" << endl;
	getline(cin, player1);
	cout<< "Please enter your name player 2" << endl;
	getline(cin, player2);

	

	for (size_t i = 0; i < 50; i++)
	{
		cout << "__";
	}
	cout << endl;
	cout << player1 + " enter a word for " + player2 << endl;
	getline(cin, word);

	for (size_t i = 0; i < word.size(); i++)
	{
		hiddenWord.push_back('_');
	}

	for (size_t i = 0; i < 30; i++)
	{
		cout << endl;
	}
	cout << "How many guesses would you like to give yourself "+player2+"?"<<endl;
	
	cin >> lives;
	cout << player2 + " time to play the game!" << endl;
	
	
	while (hiddenWord != word && lives>0) {

		for (size_t i = 0; i < lives; i++)
		{
			cout << "\\0/";
		}
		cout << endl;
		for (int i = 0; i < hiddenWord.size(); i++) {
			cout << hiddenWord[i] << ' ';
		}
		cout << endl;
		cout << "Press \'Y\' to guess the whole word or just guess a letter" << endl;
		cin >> option;
		if (option == 'Y') {
			guessRight(word);
			return 0;
		}
		else {
			guessedLetter = option;
		}
		

		
		
		for (size_t i = 0; i < hiddenWord.size(); i++)
		{
			
			
			 if (guessedLetter == word[i] && hiddenWord[i]=='_') {
				hiddenWord[i] = guessedLetter;
				break;
		}
			 if (word.find(guessedLetter)==-1) {
				 cout << "You just lost a life" << endl;
				 lives--;
				 break;
			 }
			
			
			
		}
	}
	if (hiddenWord == word) {
		for (auto c : hiddenWord) {
			cout << c << ' ';
		}
		cout << endl;
		cout << "Congratulations! You win!!!" << endl;
	}
	else {
		for (auto c : hiddenWord) {
			cout << c << ' ';
		}
		cout << endl;
		cout << "You lost! The correct word was " << word << endl;
	}
}

void guessRight(string word){
	string guessedWord;
	cout << "Oh you devil!" << endl;
	cin >> guessedWord;
	if (guessedWord == word) {
		cout << "Congratulations! You got the whole word right!"<<endl;
		
	}
	else
	{
		cout << "You lose!" << endl;
		
	}
}
