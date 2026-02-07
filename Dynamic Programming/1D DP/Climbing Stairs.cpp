/*
Here, we are standing at the bottom of the stairs and we can climb 1 or 2 stairs at a time
Return : The number of distinct ways we can reach the stairs
*/

Thinking first-

  at step 0 - 0
  at step 1 - 1 way
  step 2 - 2 ways, 1 direct climb & 2 climbing step 1 first then step 2
  step 3 - 3 ways
  step 4- 5 ways

  OBSERVATION- 
  ways(3) = ways(2) + ways(1)
  ways(4) = ways(3) + ways(2)

  Thus, this observation makes this question ENTIRELY similar to fibonacci (Solved in intro)
