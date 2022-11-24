/*
*This program classifies and calculates the aliquot sum, factors, and sequence of positive integers. <br>
* Thomas O'Donnell
* <pre>
* Date: 3/23/22
* CSC 1253 Project # 3 Section # 002
* Instructor: Dr. Duncan
* File: AliquotGenerator.cpp
* </pre>
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include<string>
using namespace std;

long rSigma(long num) {
    long sum = 0;
    if (num > 0) {
        for (int i = 1; i <= num/2; i++) {
            if ( num % i == 0 )
            sum += i;
        }
        return sum;
    }
    else return -1;
}
string genRSigSeries(long num) {
    string s;
    if ( num > 1 ) {
        s = to_string(1);
        for (int i = 2; i<= num/2; i++) {
            if (num % i == 0) {
                s += " + ";
                s += to_string(i);
            }
        }
    }
    return s;
}
void aliquot(long num, string& sequence, long& length) {
    if (num > 0) {
        sequence = to_string(num);
        while(num > 0) {
            num = rSigma(num);
            sequence += ", ";
            sequence += to_string(num);
            length++;
        }
    }
}

int main() {

   long int num1, length = 0, num2, num3, num4;
   string sequence;
   cout << "Enter a positive integer for its classification ->";
   cin >> num1;
       if ( num1 <= 0 || ((num1 / 1) != num1)) {
           cout << "ERROR: The input must be a positive integer." << endl;
       }
       else {
   cout << "s(" << num1 << ") = ";
   if(rSigma(num1) < 2){
	       	cout <<rSigma(num1) << endl;
   }
   else {
	   string s1 = genRSigSeries(num1);
	   cout << s1;
    cout << " = " << rSigma(num1) << endl;
   if (rSigma(num1) == num1) {
       cout << "s("<< num1 <<") = "<< num1 << endl;
       cout << num1 << " is a perfect number." << endl;
   }
   else if(rSigma(num1) > num1) {
       cout << "s("<< num1 << ") > "<< num1 << endl;
       cout << num1 << " is an abundant number." << endl;
   }
   else {
       cout << "s("<< num1 << ") < " << num1 << endl;
       cout << num1 << " is a deficient number." << endl;
   }
   cout << endl;
       } }
    cout << "Enter two positive integers ->";
    cin >> num2 >> num3;
    if ( (num2 <= 0 || num3 <= 0) || (num2 == num3)) {
	        cout << "ERROR: The inputs must be distinct positive integers." << endl << endl;
    }
    else {
        string s2 = genRSigSeries(num2);
        string s3 = genRSigSeries(num3);
	   	 if ( (rSigma(num2)) == num3 && (rSigma(num3) == num2)) {
	   		cout << "?amicable(" << num2 << ", " << num3 << ") = true" << endl;
	   		cout << "s("<< num2 <<") = "<< s2 << " = " << rSigma(num2) << endl;
            cout << "s("<< num3 <<") = "<< s3 << " = " << rSigma(num3) << endl;
	   	 }
	   	 else {
	     cout << "?amicable(" << num2 << ", " << num3 << ") = false" << endl;
	   	 cout <<"s("<<num2<<") = ";
	   	 if (rSigma(num2) < 2)
	   		cout<<rSigma(num2);
	   	else
	   	    cout<<s2<<" = "<< rSigma(num2);
            cout <<"\ns("<<num3<<") = ";
            if (rSigma(num3) < 2)
	   		    cout<<rSigma(num3);
	   		else
	   			cout<<s3<<" = "<< rSigma(num3);
	   	 }
    }
    cout << "\nEnter an imperfect positive integer ->"; {
    cin >> num4;
    if (num4 <= 0 || rSigma(num4) == num4) {
        cout << "ERROR: The input must be an imperfect positive integer.";
        return 0;
    }
    else {
         cout << "aliquote{"<< num4 <<"} = ";
    aliquot(num4,sequence,length);
    cout << sequence << endl;
    cout << "length: " << length + 1;
    } }
   return 0;
}
