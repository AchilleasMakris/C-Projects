// This program checks whether two given strings are anagrams by counting the 
// occurrences of characters ('a', 'b', 'c', and 'd') in each string and comparing 
// their frequency distributions.

#include<stdio.h>
#include<string.h>

int main() {
  // Arrays to store the count of 'a', 'b', 'c', and 'd' in each string
  int counter1[] = {0,0,0,0}; // Counter for first string
  int counter2[] = {0,0,0,0}; // Counter for second string

  // Input strings to be analyzed
  char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
  char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

  // Calculate the length of each string
  int string1 = strlen(s1);
  int string2 = strlen(s2);

  // Iterate through the first string and count occurrences of 'a', 'b', 'c', and 'd'
  for(int i = 0; i < string1; i++)
  {
    if (s1[i] == 'a')
    {
      counter1[0]++; // Increment counter for 'a'
    }
    else if(s1[i] == 'b')
    {
      counter1[1]++; // Increment counter for 'b'
    }
    else if(s1[i] == 'c')
    {
      counter1[2]++; // Increment counter for 'c'
    }
    else if(s1[i] == 'd')
    {
      counter1[3]++; // Increment counter for 'd'
    }
    else
    {
      continue; // Ignore spaces or other characters
    }
  }

  // Iterate through the second string and count occurrences of 'a', 'b', 'c', and 'd'
  for(int i = 0; i < string2; i++)
  {
    if (s2[i] == 'a')
    {
      counter2[0]++; // Increment counter for 'a'
    }
    else if(s2[i] == 'b')
    {
      counter2[1]++; // Increment counter for 'b'
    }
    else if(s2[i] == 'c')
    {
      counter2[2]++; // Increment counter for 'c'
    }
    else if(s2[i] == 'd')
    {
      counter2[3]++; // Increment counter for 'd'
    }
    else
    {
      continue; // Ignore spaces or other characters
    }
  }

  int flag = 0; // Flag to indicate if the strings are anagrams

  // Compare character counts for both strings
  for(int i = 0; i < 4; i++)
  {
    if(counter1[i] != counter2[i])
    {
      flag = 1; // If any character count differs, set flag to indicate mismatch
      break;
    }
  }

  // Print the result based on the comparison
  if (flag == 1)
  {
    printf("Not Anagram!");
  }
  else
  {
    printf("Anagram!");
  }
}
