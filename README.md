# Page-Replacement-Algorithms-in-OS
 In memory management, page replacement is key when a page fault occurs. If no free memory is available, a page replacement algorithm like Optimal, FIFO, or LRU is used to replace a page, storing the removed one on disk. This ensures required pages are in memory for process continuation (Tanenbaum, 2008).

Problem Statement: 
To design and develop a project to compare first in first out (FIFO) and optimal page replacement algorithms, 
for given set of page numbers, and page frames.


(1) FIFO : 

The FIFO (First-In, First-Out) page replacement algorithm is a simple and intuitive method used by operating systems to manage memory when a page fault occurs. In this algorithm, the page that has been in memory the longest is selected for replacement. 
 
Here is the full information about the FIFO page replacement algorithm: 
  
Data Structure: The FIFO algorithm uses a queue data structure to keep track of the order in which pages are loaded into memory. The queue follows a First-In, First-Out order, meaning that the page that entered the queue first will be the first one to be replaced. 
 
Page Table: The operating system maintains a page table that keeps track of the pages currently in memory and their corresponding information, such as the page number, frame number, and any additional metadata. 
 
Page Fault Handling: When a page fault occurs, indicating that the requested page is not present in memory, the operating system initiates the page replacement process. Selecting the Victim Page: The page at the front of the queue is selected as the victim page for replacement since it has been in memory the longest. The front page is the one that was loaded first and has spent the most time in memory. 

Updating the Page Table: The page table is updated to reflect the replacement. The victim page is removed from memory, and the new page is loaded into the corresponding frame. The page table is then updated with the new page's information. 
 
Updating the Queue: After the replacement, the queue is updated to reflect the new order of pages in memory. The new page is added to the back of the queue, and the victim page is removed from the front. 
 
Repeat: The process repeats whenever a page fault occurs, and the queue keeps growing until all available memory frames are occupied. 

It's important to note that the FIFO algorithm suffers from the "Belady's anomaly," which means that increasing the number of page frames can sometimes lead to an increase in the number of page faults. This anomaly occurs when a page that was previously evicted from memory by FIFO would have stayed in memory if there were fewer page frames available. 

Despite its simplicity, the FIFO algorithm is not always the most efficient in terms of overall page fault rate. Other page replacement algorithms, such as LRU (Least Recently Used) or Optimal, often provide better performance. However, FIFO remains useful due to its simplicity and low computational overhead.


(2) LRU : 

The Least Recently Used (LRU) page replacement algorithm is a popular method used by operating systems to manage memory. It works based on the principle that pages that have not been used recently are less likely to be used in the near future. The LRU algorithm replaces the least recently used page in memory with a new page when a page fault occurs. Here's a full explanation of how the LRU algorithm works: 

Maintain a data structure to track the usage of pages, such as a linked list or a queue. Each page has a timestamp or a counter associated with it to indicate when it was last accessed. 

When a page is referenced (read or written to), the operating system checks if it is present in the memory. If it is present, the page's timestamp is updated to the current time. 

If the referenced page is not present in memory (a page fault occurs), the operating system needs to select a page to evict. It examines the timestamps or counters of all pages to identify the least recently used page. 

The page identified as the least recently used is then evicted from memory to make space for the new page. 

This eviction may involve writing the page's contents back to disk if it has been modified. 

The new page is then brought into memory and its timestamp or counter is set to the current time. 

By using the LRU algorithm, the operating system ensures that the pages most likely to be used in the near future are kept in memory, while less frequently used pages are evicted. This helps to minimize page faults 
and optimize memory usage. 


(3) Optimal :

The optimal page replacement algorithm, also known as the "OPT" algorithm or the "Belady's algorithm," is an idealized algorithm for page replacement in an operating system. It assumes that it has complete information about future memory references. 

The OPT algorithm works by replacing the page that will not be used for the longest period of time in the future. It requires knowledge of the entire future sequence of memory references to make the optimal decision. 

However, in reality, it is impossible to have complete information about future memory references. Therefore, the OPT algorithm is mainly used as a benchmark to measure the performance of other page replacement algorithms. 

To illustrate how the OPT algorithm works, consider the following example: 
 
Suppose we have a memory of size N and a sequence of memory references: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5. 
 
Let's assume the memory size is 3. Initially, the memory is empty. When the first memory reference 1 arrives, we place it in an empty frame. Then, we encounter memory reference 2, and we place it in another empty frame. The next memory reference is 3, and we place it in the remaining empty frame. 

Now, when we encounter memory reference 4, we need to replace a page because all frames are occupied. Since we have complete knowledge of future memory references, we can look ahead and see that the page 1 will not be used until after the references 2, 3, 4. Therefore, we replace page 1 with page 4. 

The process continues, and we repeat the same steps until the end of the sequence. With complete knowledge, we make optimal replacements at each step. 

Again, it's important to note that the OPT algorithm is not practical for real-world implementations because it requires future information, which is not available. Instead, various approximation algorithms like LRU (Least Recently Used), FIFO (First In, First Out), and various other algorithms are used to achieve a reasonable approximation of optimal page replacement. These algorithms make decisions based on past behaviour and access patterns rather than future information.


