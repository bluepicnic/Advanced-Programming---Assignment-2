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
Had issues with initial design and my understanding of derived classes access to base class variables, while still attempting to maintain a level of encapsulation. In many cases, I worked around these by including functions in the base class to relieve any potential coupling between classes and to maintain encapsulation, but in doing so I somewhat undermined my use of runtime polymorphism, relegating my dynamic derived classes to variations on functions that took input or generated values to perform a task, such as firing a torpedo. 


## 3. Evaluation (academic standard: distinction level detail: section required for distinction) – 10%
### a. Analysis with embedded examples of key code refactoring, reuse, smells.
#### Distinction: Statements with deep justifications and discussions

#### Refactoring
Throughout the course of my battleship project, I made a conscious effort to refactor my code at various intervals, 

#### Reuse 
Purposefully using runtime polymorphism for the player classes to prevent major code reuse. Player related game functionality kept in the game class to prevent reuse, with specific instances for each type being placed into helper functions, limiting code changes to a single location and centralises any changes that needed to be made. 

#### Smells

Refrained from using string literals where possible. Kept coupling low and cohesion high. 

That being said, some less impactful aspects of coupling made its way into my code by default, such as a reliance on external modules. This, ultimately, was unavoidable, regardless of how well encapsulated it was, or if it was deferred to globally available helper functions (or design patterns such as singletons). And while it is relatively less impactful than other types of coupling, it was still present in my code. 




Kept a consistent naming convention throughout with an m prefix for each member variable. This allowed me to easily identify each variable and realise its purpose within an object, which also further contributed to the readability of my code. 

~~^^This is a really good example of the kind of writing style he's looking for~~

Potential "shotgun surgery" in places where multiple things needed to change. In reality, due to my experience with the language and object oriented design thinking, changes to my initial design required changes in multiple places to facilitate the flow of data and to fix bugs. Additionally, I made use of many globally available functions 



### b. Implementation and effective use of ‘advanced’ programming principles (with examples).
In order to demonstrate my abilities as a programmer, I made use of a number of advanced programming principles which not only contributed to the quality of my code, but also improved the logic and flow of the developed program by taking advantage of my chosen language, C++ and its specialist features. 

Chief among the advanced programming principles was that of object orientation, which is widely considered to be one of the end goals of C++, as Stroustrup developed C++ with object orientation in mind (Vartanian, 2022). However, it is argued that C++ lacks the purity of an object oriented language such as Java (Why C++ is partially Object Oriented Language? - GeeksforGeeks, 2017), as it is not solely reliant on objects in order to implement basic functionality and is deemed a multi-paradigm language as such. That being said, the inclusion of the option to program in an object oriented fashion, along with it being a popular paradigm to follow, illustrates that C++ lends itself well to the principle. 

In the case of my project, I had object orientation in mind from the very beginning, which can be seen in the pattern that emerged through my file structure and code. ![File structure used, many containing the definitions and implementations of individual classes](Images/1762c6649af7768f1a50b6e39cfebd9b.png) 

This essentially decomposed each aspect of the game of battleship into its own set of objects. Such as the concept of the game itself and its associated features and attributes, seen below: 

![Example of "Game" class, containing associated functions and member variables](Images/65bf4eca3db40f8c625272c71c367f4d.png) 


This not only lent itself well to development of a game such as this, but also presented an oppurtunity to encapsulate each of these objects in C++'s supported classes, which allowed myself to consider the separate functionality and associated data of each object. While many of these considerations were pondered well in advance of development commencing, the act of implementing these objects according to a premeditated design, while keeping in line with C++ explicit rules, was a challenge in of itself. Due to my lack of professional experience with C++ as a language, many aspects of my initial design changed over the course of development. Regardless, I managed to stick to object orientation as a paradigm, even if I strayed from my initial design.

An important consideration, in keeping with object oriented design principles, was the relationship between objects. These were an aspect of my initial design that remained constant throughout the development of my project. During my initial designs, I specified the relationships between each associated object. For example, in my UML diagram, I made note of the fact that each "game" class instance has exactly two "players" class instances associated with a composition relationship; that is, a relationship which is wholly reliant on the lifetime of the "game" object, as without it, the associated players would not exist (IBM Docs, 2021). Implementing this in my program was relatively simple, my game class needed to be setup with two players as data members. In the context of access modifiers, the decision was already laid out in my UML design, but was ultimately inconsequential when describing and implementing the relationship between the game and player classes in this instance. 

Deeper considerations did need to be given however, for variations of my player class, and the way in which data was shared between them. This relationship, inheritence, can be directly implemented and described in C++ when creating a class that derrives from a "base" class. In this case, I had a base "player" class which two subclasses, "AIPlayer" and "HumanPlayer", inherited from. These were created to fulfil functionality specific to each type of player that was featured in my game project. For example, a HumanPlayer class instance is able to directly set its name upon creation, based on user input. This required its own function, "declarePlayerName", which is not present in the AIPlayer class, despite both derived player classes inheriting the mPlayerName variable. Where the implementation differs between classes, is that an AIPlayer will always have its name set to "Player" by default, with no need to set a custom name. This is a design decision that I came up with based on implementations in other games, where computer controlled players would have static, generic names, which I felt was suitable for this project. Depending on the type of inheritence I specified, this would affect the two derived class's access to variables and functions in the base class. For the sake of my project, I chose public inheritence, which gave my inherited classes the same level of access as my base class to functions and variables as they were initially defined. This level of access was chosen as each implementation of an "AIPlayer" or "HumanPlayer" still needed access to attributes such as a player name, battleship game boards, and ships used for gameplay. In addition, this helped to prevent code reuse, as these attributes would not need to be repeated in the derived classes. Furthermore, my implementation did not call for a greater level of security that the other access modifiers, private and protected, would provide, nor did any data in the base class need to be obscured. 

Functions in my base class were publically available for use where instances of "player" or derived "player" objects were found. This was done for ease of access, while at the same time not allowing direct access to member variables, which were defined as private. Where I wanted my implementation of these functions to differ from the base class, I had to exhibit polymorphism. This was mostly implemented where common functionality from the base class would not apply to aspects of the derived classes. For example, the way in which each type of player places their ships on the game boards is not always identical, as an AI player will always do so randomly, whereas a Human player is able to choose between manual and various levels of automatic placement. For this purpose, I created a polymorpic function in the HumanPlayer derived class to account for this extra functionality. The "virtual" c++ keyword was utilised alongside the same function definition in the base class to account for this variance, and therefore, whenever a human player opts for the manual of boat placement, the correct version of the function is used for Human players, rather than the one declared in the base class. 

This was done to avoid code repetition and ensure that any early binding by the compiler did not occur, which would result in the wrong function implementation being called. Bugs caused by early binding can be hard to debug, so I opted to avoid encountering them altogether. 

Additionally, standard polymorphism combined with user defined objects allowed for behaviour specific to one of the derived player classes to be defined within the construstor, in addition to the standard initialisation provided by the base class. 

In the context of C++, when one refers to Polymorphism, it is often assumed that they are referring to the concept of Polymorphism with late binding. (Eckel and Allison, 2004) believe that the term should only be used to refer to this type of polymorphism, commonly known as runtime polymorphism. 

The benefits of runtime polymorphism are thus; to be able to invoke the functions of objects at runtime, rather than compile time. This means that the type of the object itself doesn't even need to be known in order to invoke the function, due to the inclusion of a base class pointer. This provides a level of flexibility in exchange for a slight performance hit, especially in the case of this project, where this type of polymorphism is only achieved once per game object lifetime. 

I felt this lent itself quite well to my project since I had multiple player class types included as part of my initial design, and utilising runtime polymorphism would enable me to make specific calls to member functions of those derived classes without including any extra code, or explicitly having to define instances of those object types. The inclusion of this 'advanced' feature may not have been used to its full potential from my perspective, but I still believe that its inclusion and implementation are valid.

Implementing runtime polymorphism necessitated the use of dynamic memory allocation and pointers. This, at face value, betrayed one of the 15 standards in not conserving system resources, and opened my program up to potentially unwanted behaviour via memory leaks, which can be dangerous for a program. However, relatively speaking, my player classes have quite a minimal memory impact and overall size in bytes. In addition, I was very much aware of the scope of any player objects created, as outlined in my UML diagram, which noted that they are intrinsically tied to the lifetime of my Game class object. Therefore, so long as appropriate measures were taken to release the allocated memory upon each Game object's destruction, memory leaks would be prevented and system resources would be conserved. I would then be able to reap the benefits of dynamic memory allocation and runtime polymorphism without fear of memory based issues within my project. 

I also utilised 

~~Object orientation~~

~~Inheritence~~

~~Polymorphism~~ 

~~Pointers & RuntimePolymorphism~~

IO + Input parsing
Use of various regex functions and patterns to ensure the exact input was being assessed, file reading and parsing

Design Patterns (Finite State Machines)
Use of finite state machines lends itself well to game development and allows various objects which have a variety of phases to be tracked and react accordingly to a given situation.



### c. Features showcase and embedded innovations (with examples) - opportunity to ‘highlight’ best bits.

Conversion of letters to numbers
Relevant state machines
Grouping of common values into user defined structs
Runtime polymorphism and use of pointers (creation of dynamic objects)
Recursive functions
Generate players
Depth first search if I get around to it

### d. Improved algorithms – research, design, implementation, and tested confirmation (with examples).

File parser
Conversion of numbers to letters
Conversion of letters to numbers
Pure check input function


### e. Reflective review, opportunities to improve and continued professional development.
My understanding of C++'s ability to facilitate OOP I think is quite good, but I often find it difficult to think in an object oriented way. My background as a programmer revolved around repitition of many of the basic aspects of C++ which resulted programming in a procedural and sometimes functional way.

For the sake of this project, which I thought lent itself well to object oriented design and thinking, I found it quite intuitive to create UML notation and diagrams for the project and was able to think and create what I believed to be quite a solid initial system, with correct relationships and instances between each object. I would like to try and apply this thinking to a more unorthodox system at some point in the future, to see if I can apply the same logic and reasoning to another project. 

Many advanced aspects of the language such as multithreading, templates, and exceptions went unused in my project. While this simply could have been an instance of it not being suitable for the project, I felt as if my understanding of these aspects was not deep enough to be able to utilise these useful tools effectively. For example, template types and generic functions would have worked well alongside my many user defined types and classes, and yet 

Difficulty seeing the bigger picture when planning, making it tough to estimate a time to completion for each task, which increases the scope of each set of features, which ultimately would not be acceptable in a professional environment. Although, depending on the size of a team in a professional environment, the act of decomposition and discovering the solution to a problem could be the responsibility of other members of the development team, for example Business analysts and senior programmers. Regardless, it is a vital skill 

## References
- Vartanian, E., 2022. Is C++ an object-oriented programming language?. [online] Educative: Interactive Courses for Software Developers. Available at: <https://www.educative.io/blog/is-cpp-object-oriented-programming-language>
- GeeksforGeeks. 2017. Why C++ is partially Object Oriented Language? - GeeksforGeeks. [online] Available at: <https://www.geeksforgeeks.org/c-partially-object-oriented-language/>
- Ibm.com. 2021. IBM Docs. [online] Available at: <https://www.ibm.com/docs/en/rational-soft-arch/9.5?topic=diagrams-relationships-in-class>
- Eckel, B. and Allison, C., 2004. Thinking in C++. Upper Saddle River, N.J.: Prentice Hall, p.716.

