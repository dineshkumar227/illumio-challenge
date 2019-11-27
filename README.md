# illumio-challenge
My coding challenge submission for the Intern System Software Engineer, VEN 2020 role.

## Decisions I made:
* Challenge Definitions:
    * When matching an address, the more specific one is preferred. For example, 192.168.1.1:8080 will match with both *:8080 and 192.168.1.1:8080, the latter will be preferred as it is a closer match.
    * Address matches are a higher priority over port matches. Example: 192.168.1.1:8080 matches with both 192.168.1.1:* and *:8080. The former is preferred.
    
* Data Structure used: Ordered map in reverse order
    * Maps are efficient for looking up matches. 
    * To find matches with addresses iteration is required, which is why we cannot use an unordered map even though it is faster (O(logN) vs O(1)).
    * By ordering maps in reverse, more specific addresses are naturally placed higher than wildcards when iterating through the elements (192.168.1.1:8080 will be placed before *:8080).

## Things I would have worked on:
* Cleaned up code a bit more and move the read and write functions to a separate file or class.
* Made a more sophisticated matching algorithm that would support more advanced wildcards like *.168.1.1:8080
