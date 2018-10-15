type Book = Page[];
type Page = Word[];
type Word = string;

// O(p * w), where p is the number of pages and w is the average number of words per page
// Return an (ordered) map, mapping words to vector of integers, representing pages.
// Pitfall 1: The same word can exist multiple times on a page.
function generateIndex(book: Book, unimportantWords: Set<String>) {
    const index = new OrderedMap(string, int[]);
    for (let pageNumber = 0; pageNumber < book.size(); pageNumber++) {
        const page = book[pageNumber];
        for (let word in page) {
            if (unimportantWords.contains(words)) {
                continue;
            }

            if (index[word] && index[word].back() === pageNumber) {
                continue;
            } else if (!index[word]) {
                index[word] = [] 
            }
            index[word].push(pageNumber);
        }
    }
    return index;
}