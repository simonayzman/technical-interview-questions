### Exam Preparedness

In order for a student to be considered as understanding a set of material in a textbook, they need to at least have read it X times. Given the required pages (a fixed number of pages, k), the number of times a single page must be read to be understood, and a finite stream of how the student read the pages (an array of page numbers), determine whether the student understands the material required for the exam. Note that the required pages are assumed to be from 1 to k. Note that the pages read by the student could be out of order, not necessarily required for the exam, and could exceed the number of times necessary for a single page. An example stream is passed in like so:

[1,2,3,4,1,3,4,1,2,3,4,5,6,7,8,3,4,5,6,7]

Modification 1: The required pages could be many un-contiguous ranges of pages. In other words, instead of being a vector of required pages, the function is passed a sorted array of tuples, with each tuple representing a start/end page range and all the tuples in totality representing ALL of the required pages.

Modification 2: How would we deal with this if the pages read are not a finite stream, but rather, occur in ticks, i.e., every time a page is read, a pageRead function is called.

\[[Solution](solution.cpp)\]
