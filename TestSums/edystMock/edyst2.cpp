// Exam Efficiency
// In an examination with multiple choice questions, the following is the exam question pattern.

// X1 number of One mark questions, having negative score of -1 for answering wrong
// X2 number of Two mark questions, having negative score of -1 and -2 for one or both options wrong
// X3 number of Three mark questions, having negative score of -1, -2 and -3 for one, two or all three options wrong
// Score Required to Pass the exam : Y
// For 1,2 and 3 mark questions, 1,2 and 3 options must be selected. Simply put, once has to attempt to answer all questions against all options.
// Identify the minimum accuracy rate required for each type of question to crack the exam.

// Calculations must be done up to 11 precision and printing up to 2 digit precision with ceil value

// Input Format:
// First line contains number of one mark questions denoted by X1,
// Second line contains number of two mark questions denoted by X2
// Third line contains number of three mark questions denoted by X3
// Fourth line contains number of marks required to pass the exam denoted by Y.
// Output Format:
// Minimum Accuracy rate required for One mark question is 80%
// Minimum Accuracy rate required for Two mark question is 83.33%
// Minimum Accuracy rate required for Three mark question is 90%
// Note:- If the mark required to pass the exam can be achieved by attempting without attempting any particular type of question then show message similar to, One mark question need not be attempted, so no minimum accuracy rate applicable

// See Example Test cases for better understanding.

// Sample Input / Output
// Input	Output	Explanation
// 20
// 30
// 30
// 120
// One mark questions need not be attempted, so no minimum accuracy rate applicable.
// Minimum Accuracy rate required for Two mark question is 58.33%
// Minimum Accuracy rate required for Three mark question is 72.23%	If one got full marks in two marks question and three marks question then total accuracy can be 0 in one mark question
// In same way it will be done for two marks and three marks question

// 20
// 30
// 30
// 170
// Minimum Accuracy rate required for one mark question is 100%
// Minimum Accuracy rate required for Two mark question is 100%
// Minimum Accuracy rate required for Three mark question is 100%	If one got full marks in two marks question and three marks question then total accuracy should be 100% in one mark question to pass the exam.
// In same way it will be done for two marks and three marks question