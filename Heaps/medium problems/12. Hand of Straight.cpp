//846. Hand of Straights
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

//Brute Force Approach-
  1. Sort the entire array
  2. Pick the smallest element and create group of consecutive members
-> if we'll check for i and i+1 it'll fail because of duplicates
//Code
