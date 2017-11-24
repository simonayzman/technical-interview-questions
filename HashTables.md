#### Hash Tables

Implement a data structure that accomplishes key/value pair insertion in O(1)
time, key/value pair removal in O(1) time, key existence confirmation in O(1)
time, random key/value pair retrieval in O(1) time.

// InstaRandom class contains a hash table of key/value pairs, an array of keys,
// and another hash table that maps the keys to their index positions in the
// array. Remove is the most complicated function to implement because it
// requires the subsequent holes in the key array to be filled (by swapping the
// removed key with the last key and updating the second hash table).
