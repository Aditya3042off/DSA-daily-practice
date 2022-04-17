// There are M number of vaccination centres in a city. N number of people have registered for the vaccination on a particular day. You are given their details in form of age, name, category and location. Vaccination centres and people's location will be given in the form of coordinates. People are divided into two categories, category A and category B. People who belong to category A will get vaccinated first and then the people who belong to category B.

// Your task is to map people to the nearest centre. If the distance from two or more centres is the same, then map that person to the centre which appears first in the input.

// Next, you must organize the people who are assigned to same centres to take the vaccine. Priority will be based on conditions mentioned below:

// Older person will get vaccinated first
// If the age is same, they will get vaccinated according to their Category.
// If Age and Category both are same, they will get vaccinated according to their name. (Lexicographical order)
// You are given a data of N people and you must process this data on the basis of the priority as explained above.
// Constraints
// 0 < M <= 10
// 0 < N <= 50
// Input Format
// First line contains an integer M which is number of vaccination centres
// Next M lines contain 2 space delimited integers which denote the latitude and longitude of the mth vaccination centre
// Next line contains an integer N, which is number of people to be vaccinated
// Next N lines provide people data in format <Name, Age, Category, Latitude of location, Longitude of location>
// For better understanding refer the Examples section
// Output Format
// Print names of all people who got vaccinated in mth centre on same line i.e., all people who got vaccinated in centre 1 should be printed on first line
// Names should be space delimited
// Names on the same line should be in the same order as the order in which they got vaccinated
// If nobody is assigned to a vaccination centre, and say its index was n, then print "Empty Centre" on Nth line of the output
// For better understanding refer the Examples section

// Example Input #1
// 2
// 0 0
// 0 10
// 5
// Atul 24 A 0 1
// Sunil 24 B 0 5
// Rajni 23 A 0 1
// Salman 21 B 0 12
// Kunal 24 A 0 2
// Output
// Atul Kunal Sunil Rajni
// Salman
// Explanation:
// Given M = 2, N = 5

// Vaccination centre 1 location:
// Latitude: 0 Longitude = 0
// Vaccination centre 2 location:
// Latitude: 0 Longitude = 10

// Information of people:

// Atul 24 A 0 1
// Atul's age is 24. He belongs to A category and his location is {Latitude: 0 Longitude = 1}.
// The nearest centre he can get is centre 1. So, we map him to centre 1.
// Sunil 24 B 0 5
// Sunil's age is 24. He belongs to category B and his location is {Latitude: 0 Longitude = 5}
// Both the centres are at same distance from his place, but we will map him to the first one (According to the constraints).
// Rajni 23 A 0 1
// Rajni's age is 23. She belongs to A category and his location is {Latitude: 0 Longitude = 1}
// The nearest centre she can get is centre 1. So, we map her to centre 1.
// Salman 21 B 0 12
// Salman's age is 21. He belongs to B category and his location is {Latitude: 0 Longitude = 12}.
// The nearest centre he can get is centre 1. So, we map him to centre 2.
// Kunal 24 A 0 2
// Kunal's age is 24. He belongs to A category and his location is {Latitude: 0 Longitude = 2}.
// The nearest centre he can get is centre 1. So, we map him to centre 1.
// After allotting centres to all the people we have:
// Vaccination centre 1: Atul, Sunil, Rajni, Kunal
// Vaccination centre 2: Salman
// But our task is also to order them according to priority for a particular centre.
// For Vaccination centre 1: If we order them according to their age, we get (Atul = Sunil = Kunal) > Rajni. Three people are having same age. So, now we have to sort them on the basis of their category. Atul belongs to A, Sunil belongs to B and Kunal belongs to A. Which is (Atul = Kunal) < Sunil
// Now Atul and Kunal belongs to same category. So, we sort them on the basis of their name. Which is (Atul < Kunal)
// Finally, we have order of centre one as: Atul, Kunal, Sunil, Rajni
// We print (vaccination centre 1)'s output on the first line.
// For Vaccination centre 2: There is only one person allotted to this centre. We don't have to perform any ordering here. We print (vaccination centre 2)'s output in second line.

// Example Input 2
// 3
// 0 1
// 0 5
// 0 10
// 3
// Atul 24 A 0 2
// Niraj 22 A 0 3
// Shivam 21 B 0 2

// Output
// Atul Niraj Shivam
// Empty Centre
// Empty Centre
// Explanation:
// All the people are having centre 1 as the nearest centre from their location. So, we will send them all to centre 1 and sort them on the basis of age-category-name.