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

###d. Analysis and decomposition of the overall problem into key ‘epic’ style tasks (linked to 1b, 1c).
Made use of Jira to consider high level tasks and concepts


###e. Initial object-oriented design ideas and planned phased breakdown into smaller tasks (linked to 1d).
Later broke down into smaller individual tasks based on actions each object needed to take 
Initially done from a physical battleship game point of view, was then adapted from a programming perspective 

----

## 2. Development (academic standard: merit level detail: section required for merit) – 15%
### a. Adoption and use of ‘good’ standards (linked to 1a, 1b, 1c).
All of em
### b. Phase 1 development: tasks, code review and changes (linked to 1d,1e).
Phase 1 development consisted of wider helper functions that dealt with output, input and file parsing and implementing polymorphism. 
Considered how current code state would affect future development during review. 

Initial structure of many classes changed. Initially over-relied on pointers, but scaled their uses back to just the abstract player class. Which wasn't originally meant to remain an abstract class.

Refactored during and after a development phase was complete
### c. ..repeated for each development phase.
### d. Phase n development: tasks, code review and changes (linked to 1d,1e).
### e. Ensuring quality through testing and resolving bugs (linked to 1a, 1b, 2a, 2b..2c).
Before I moved jira to move anytasks between swimlanes, I always made sure to test each individual feature independently. Because of the modular nature of object oriented programming, 
### f. Reflection on key design challenges, innovations and how they were solved (with examples).
Talk about the player and player class
Displaying the board and spaces
Correct output for each player 
Created my own problem with use of pointers, but due to deep understanding of the game, knew exactly how long their lifetimes were. 
----

## 3. Evaluation (academic standard: distinction level detail: section required for distinction) – 10%
### a. Analysis with embedded examples of key code refactoring, reuse, smells.
Refrained from using string literals where possible. Kept coupling low and cohesion high. 

Purposefully using runtime polymorphism for the player classes to prevent major code reuse. Player related game functionality kept in the game class to prevent reuse, with specific instances for each type being placed into helper functions, limiting code changes to a single location and centralises any changes that needed to be made. 

Kept a consistent naming convention throughout with an m prefix for each member variable. This allowed me to easily identify each variable and realise its purpose within an object, which also further contributed to the readability of my code. 

~~^^This is a really good example of the kind of writing style he's looking for~~


### b. Implementation and effective use of ‘advanced’ programming principles (with examples).
Polymorphism, Finite State Machines, Inheritence, Pointers, Runtime polymorphism
### c. Features showcase and embedded innovations (with examples) - opportunity to ‘highlight’ best bits.
### d. Improved algorithms – research, design, implementation, and tested confirmation (with examples).
### e. Reflective review, opportunities to improve and continued professional development.
My understanding of C++'s ability to facilitate OOP I think is quite good, but I often find it difficult to think in an object oriented way. My background as a programmer revolved around repitition of many of the basic aspects of C++ which resulted programming in a procedural and sometimes functional way.

 For the sake of this project, which I thought lent itself well to object oriented design and thinking, I found it quite intuitive to create UML notation and diagrams for the project and was able to think and create what I believed to be quite a solid initial system, with correct relationships and instances between each object. I would like to try and apply this thinking to a more unorthodox system at some point in the future, to see if I can apply the same logic and reasoning to another project. 

Many advanced aspects of the language such a multithreading, templates, and exceptions went unused in my project. While this simply could have been an instance of it not being suitable for the project, (continue)