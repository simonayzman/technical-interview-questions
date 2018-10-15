// O(n)
// Handles skip pointing to itself, backwards, and outside of the lists
// Also handles cycles, which is melded with skip checks for self and backwards
bool validateSkipList(Node* head) {
    unordered_set<Node*> seenNodes;

    Node* curr = head;
    while (curr) {
        seenNodes.add(curr);
        if (seenNodes.contains(curr->skip) || seenNodes.contains(curr->next)) {
            return false;
        }
        curr = curr->next;
    }

    curr = head;
    while (curr) {
        if (!seenNodes.contains(curr->skip)) {
            return false;
        }
        curr = curr->next;
    }

    return true;
}