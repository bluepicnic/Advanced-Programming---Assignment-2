Indentation style is Stroustrup, with { used on the same line except when implementing a function. New lines are used when determining logic flow to improve readability by controlling the verticality of my code. 

My naming convention follows some of Stroustrup's recommendations including capitalising the first letters of variables names (to differentiate them from C++'s built in types and avoiding full capitalisation to prevent clashes with Macros, which, admitedly, go unused in my code.

Stroustrup recommends that his rules should be used as a guideline only if there are no solid standards to adhere to or if the developer has no better ideas. With that in mind, I adapted some of his standards and applied some of my own preferences to create the programming style which I attempted to consistently follow throughout the project.  

Following these principles, I also made use of enumerated classes to prevent unwanted type conversion for my state enums. 

## Challenge Outline (academic standard: pass level detail: section required for pass) – 10%
### a. Summary and review of the problem, overall proposed solution.
Creation of Battleship (adaship)

### b. UML style diagram illustrating initial overall solution (linked to 1a)

Initial problem which did not include utility functions and overall globally used functions that were not tied to an object. However, these were considered alongside objects

### c. Initial working plan, overall approach, development strategy and approach to quality (linked to 1a,1b).
Breaking down (not just mentally ;) ) actively defining the actions my system was going to take.

Tackling no more than 4 related tasks at a time (although as time went on I found myself getting sidetracked )

### d. Analysis and decomposition of the overall problem into key ‘epic’ style tasks (linked to 1b, 1c).
Made use of Jira to consider high level tasks and concepts


### e. Initial object-oriented design ideas and planned phased breakdown into smaller tasks (linked to 1d).
Later broke down into smaller individual tasks based on actions each object needed to take 
Initially done from a physical battleship game point of view, was then adapted from a programming perspective 

----

## 2. Development (academic standard: merit level detail: section required for merit) – 15%
### a. Adoption and use of ‘good’ standards (linked to 1a, 1b, 1c).
All of em
### b. Phase 1 development: tasks, code review and changes (linked to 1d,1e).

#### Merit: Statements with justifications/evidence/
#### "Yes, because x/y"


Phase 1 development consisted of wider helper functions that dealt with output, input and file parsing and implementing polymorphism. 
Considered how current code state would affect future development during review. 

Initial structure of many classes changed. Initially over-relied on pointers, but scaled their uses back to just the abstract player class. Which wasn't originally meant to remain an abstract class.

Refactored during and after a development phase was complete
### c. ..repeated for each development phase.
### d. Phase n development: tasks, code review and changes (linked to 1d,1e).
### e. Ensuring quality through testing and resolving bugs (linked to 1a, 1b, 2a, 2b..2c).
Before I moved jira to move anytasks between swimlanes, I always made sure to test each individual feature independently. Because of the modular nature of object oriented programming, this was made quite easy
### f. Reflection on key design challenges, innovations and how they were solved (with examples).
Talk about the player and player class
Displaying the board and spaces
Correct output for each player 
Created my own problem with use of pointers, but due to deep understanding of the game, knew exactly how long their lifetimes were. 


## 3. Evaluation (academic standard: distinction level detail: section required for distinction) – 10%
### a. Analysis with embedded examples of key code refactoring, reuse, smells.
#### Distinction: Statements with deep justifications and discussions

Throughout the course of my battleship project, I made a conscious effort to refactor my code at various intervals 

Refrained from using string literals where possible. Kept coupling low and cohesion high. 



Purposefully using runtime polymorphism for the player classes to prevent major code reuse. Player related game functionality kept in the game class to prevent reuse, with specific instances for each type being placed into helper functions, limiting code changes to a single location and centralises any changes that needed to be made. 

Kept a consistent naming convention throughout with an m prefix for each member variable. This allowed me to easily identify each variable and realise its purpose within an object, which also further contributed to the readability of my code. 

~~^^This is a really good example of the kind of writing style he's looking for~~


### b. Implementation and effective use of ‘advanced’ programming principles (with examples).
In order to demonstrate my abilities as a programmer, I made use of a number of advanced programming principles which not only contributed to the quality of my code, but also improved the logic and flow of the developed program by taking advantage of my chosen language, C++ and its specialist features. 


Object orientation
Inheritence
Polymorphism
Runtime Polymorphism
Pointers
IO + Input parsing
Design Patterns
Recursion

Chief among the advanced programming principles was that of object orientation, which is widely considered to be one of the end goals of C++, as Stroustrup developed C++ with object orientation in mind (Vartanian, 2022). However, it is argued that C++ lacks the purity of an object oriented language such as Java (Why C++ is partially Object Oriented Language? - GeeksforGeeks, 2017), as it is not solely reliant on objects in order to implement basic functionality and is deemed a multi-paradigm language as such. That being said, the inclusion of the option to program in an object oriented fashion, along with it being a popular paradigm to follow, illustrates that C++ lends itself well to the principle. 

In the case of my project, I had object orientation in mind from the very beginning, which can be seen in the pattern that emerged through my file structure and code. ![File structure used, many containing the definitions and implementations of individual classes](Images/1762c6649af7768f1a50b6e39cfebd9b.png) 

Essentially decomposing each aspect of the game of battleship into its own set of objects. This not only lent itself well to development of a game such as this, but also presented an oppurtunity to encapsulate each of these objects in C++'s supported classes, which allowed myself to consider the separate functionality and associated data of each object. While many of these considerations were pondered well in advance of development commencing, the act of implementing these objects, while keeping in line with C++ explicit rules 



Polymorphism, Finite State Machine design pattern, Inheritence, Pointers, Runtime polymorphism, recursion, object orientation (classes and objects), IO and input parsing
### c. Features showcase and embedded innovations (with examples) - opportunity to ‘highlight’ best bits.

Conversion of letters to numbers
Relevant state machines
Grouping of common values into user defined structs
Runtime polymorphism and use of pointers (creation of dynamic objects)
Recursive functions

### d. Improved algorithms – research, design, implementation, and tested confirmation (with examples).

### e. Reflective review, opportunities to improve and continued professional development.
My understanding of C++'s ability to facilitate OOP I think is quite good, but I often find it difficult to think in an object oriented way. My background as a programmer revolved around repitition of many of the basic aspects of C++ which resulted programming in a procedural and sometimes functional way.

For the sake of this project, which I thought lent itself well to object oriented design and thinking, I found it quite intuitive to create UML notation and diagrams for the project and was able to think and create what I believed to be quite a solid initial system, with correct relationships and instances between each object. I would like to try and apply this thinking to a more unorthodox system at some point in the future, to see if I can apply the same logic and reasoning to another project. 

Many advanced aspects of the language such a multithreading, templates, and exceptions went unused in my project. While this simply could have been an instance of it not being suitable for the project, (continue)

Difficulty seeing the bigger picture when planning, making it tough to estimate a time to completion for each task, which increases the scope of each set of features, which ultimately would not be acceptable in a professional environment. Although, depending on the size of a team in a professional environment, the act of decomposition and discovering the solution to a problem could be the responsibility of other members of the development team, for example Business analysts and senior programmers. Regardless, it is a vital skill 

## References
- Vartanian, E., 2022. Is C++ an object-oriented programming language?. [online] Educative: Interactive Courses for Software Developers. Available at: <https://www.educative.io/blog/is-cpp-object-oriented-programming-language>
- GeeksforGeeks. 2017. Why C++ is partially Object Oriented Language? - GeeksforGeeks. [online] Available at: <https://www.geeksforgeeks.org/c-partially-object-oriented-language/>

