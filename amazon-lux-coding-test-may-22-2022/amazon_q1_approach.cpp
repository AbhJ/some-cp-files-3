In this problem, we use hashing to store the indices of the songs having a particular songDuration

We initially reduce the rideDuration by 30, as the sum of the songDurations needs to be rideDuration - 30.

We initialize a vector v with the indices and durations of the songs
We sort the vector v so that we have the songs with the highest durations followed by the least indices at the end. 
The special corner case in which all the songs have the same duration is handled
We iterate through the vector v in a reversed fashion and each time
We check whether a pair is formed by looking up 'rideDuration - v[i].first' in the hash table m.
In case the pair is formed, we insert it into vector 'ans'
The song index of the current song is mapped to its duration for later lookup
Handling the corner case of no possible pairs
Sort the ans vector to find out the best possible pair
Return the best possible pair
The complexity of code is O(n) space and O(n log n) time where n is the number of songs.

The log n factor comes in due to the look - up time in the hashtable and sorting the vectors v and ans each of size O(n)