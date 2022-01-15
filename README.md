# Determin-Final-Grades

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Determine-Final-Grade.cpp  (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 10. Project 1.
This program  averages 5 test scores based on weight to determine a final grade. Demonstrates ability to use multiple functions and math in c++.
Written using Microsoft Visual Studio. 

## Algorithm

1. Create a structure which can hold all of the following, with the following weights:
			- Score for quiz 1 - 12.5%
			- Score for quiz 2 - 12.5%
			- Score for midterm - 25%
			- Score for final exam - 50%
			- Total numeric score
			- Letter grade
		2. Take input of quizzes and big exams
			- Define a function that takes the max score as a parameter to test input
		3. Calculate total numeric score and letter grade
			3a. Formula is: Grade = (TEST_SCORE / MAX_SCORE) * WEIGHT + (each other test following the previous formula)
				3aa. Can combine quiz1 and quiz2 then divide by 20 to use a weight of 25 instead of 12.5 for each
			3b. Calculate letter grade from numeric score - routine
		4. Output - routine

## Requirements
No requirements or modules needed for running this program.
