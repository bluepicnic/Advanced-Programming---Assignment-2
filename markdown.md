


## Challenge Outline (academic standard: pass level detail: section required for pass) – 10%
### a. Summary and review of the problem, overall proposed solution.
The problem 
Creation of Battleship (adaship)

### b. UML style diagram illustrating initial overall solution (linked to 1a)

Initial problem which did not include utility functions and overall globally used functions that were not tied to an object. However, these were considered alongside objects

### c. Initial working plan, overall approach, development strategy and approach to quality (linked to 1a,1b).
Breaking down (not just mentally ;) ) actively defining the actions my system was going to take.

Tackling no more than 4 related tasks at a time (although as time went on I found myself getting sidetracked )




### d. Analysis and decomposition of the overall problem into key ‘epic’ style tasks (linked to 1b, 1c).
Made use of Jira to consider high level tasks and concepts
Wider considerations such as game modes and overall handling of particular functionality (file, input parsing)


### e. Initial object-oriented design ideas and planned phased breakdown into smaller tasks (linked to 1d).
Later broke down into smaller individual tasks based on actions each object needed to take 
Initially done from a physical battleship game point of view, was then adapted from a programming perspective 

----

## 2. Development (academic standard: merit level detail: section required for merit) – 15%
### a. Adoption and use of ‘good’ standards (linked to 1a, 1b, 1c).
#### Merit: Statements with justifications/evidence/
#### "Yes, because x/y"
As part of my development strategy, I adopted and utilised a number of "good" programming standards that contributed to my code being readable and logical, in addition to encouraging good habits from the perspective of the programmer. This section will discuss the standard I personally adopted.

The first of these was adopting good quality, jargon free comments, so that the purpose of my code could be understood by all who read it. Where possible, I avoided using programming specific terms and attempted to keep comments within the context of the battleship game itself, unless the inclusion of these terms is vital to assist in understanding a given code block's purpose. An example of this is below:
```
int ui_displayBoatPlacement() 
{
  //don't clear screen, we need board to be displayed 
  cout << endl << manual_Boat_Selection << endl //manually place ship
  << auto_Boat_Selection << endl //auto place ship
  << auto_Place_Remaining << endl //auto place boats with an "inactive" state
  << auto_Place_All << endl //auto place all boats
  << reset_Boats << endl //recall all boats
  << complete_Setup << endl << endl //complete setup and continue
  << exit_text << endl << endl << endl; //exit

  return stoi(getLineSingleKey(regex_Menu_Selection, invalid_Menu_Input)); //take input, return as integer
}
```

I also attempted to minimise any code block duplication, which contributes overall to readability and avoids redundancy. I achieved this in many instances by taking the code in question and refactoring/placing it into its own function, where applicable. Below is a before and after comparison from an old version of my file parser function, with numerous repetitions, and the current version respectively:

##### Before
```
if(line.find('x')) {
	getline(configFile, line, 'x');
} else {
	getline(configFile, line, 'X');
}

removeLeadTrailSpaces(line);
boardWidth = stoi(line);

getline(configFile, line);
removeLeadTrailSpaces(line);
boardHeight = stoi(line);
```
##### After
```
if(line.find('x')) { //look for a lower case 
          delim = 'x';
        } else { //just in case the board has an upper case x
          delim = 'X';
        }
        getline(configFile, line);
        
        parameters = extractFileParameters(line, delim);
        
        boardWidth = stoi(removeLeadTrailSpaces(parameters[0]));
        boardHeight = stoi(removeLeadTrailSpaces(parameters[1]));
 ```


My naming convention follows some of Stroustrup's recommendations including avoiding capitalising the first letters of variables names (to differentiate them from C++'s built in types and avoiding full capitalisation to prevent clashes with Macros, which, admitedly, go unused in my code.

Following these principles, I also made use of enumerated classes to prevent unwanted type conversion for my state enums. 


3. Strive for simplicity in logic and flow.


Use a consistent naming convention for functions, variables, objects, etc to provide clear contextual value, improved comprehension, and quick readability.

One aspect of the "good" standards I always pay close attention to are the naming conventions I used for my variables, functions and objects. I do so in order to provide contextual value at first glance so that different aspects can be identified easily. For this project I used the following conventions: for all variables and function names, I used camel casing as it is my preferred method for standard code identifiers. Classes and user defined types (structs, enums) are defined with capital first letters to differentiate them from C++'s built in types. Class member variables begin with an "m" prefix, which I do not apply to structs in order to enable differentiation between them. Finally, any constant values follow camel casing with underscores between words, this is to make them stand out and be immediately identifiable next to variables.  This naming convention follows some of Bjarn Stroustrup's recommendations including avoiding capitalising the first letters of variables names (to differentiate them from types (C++'s own and my user defined ones) and avoiding full capitalisation to prevent clashes with Macros, which, admitedly, go unused in my code.

Stroustrup recommends that his rules should be used as a guideline only if there are no solid standards to adhere to or if the developer has no better ideas. With that in mind, I adapted some of his standards and applied some of my own preferences to create the programming style which I attempted to consistently follow throughout the project.  

The next set of standards all related to indentation, spacing, and alignment. 

Indentation style is Stroustrup, with { used on the same line except when implementing a function. New lines are used when determining logic flow to improve readability by controlling the verticality of my code. 

5. Use appropriate and consistent indentation, logical grouping and spaced blocks within your codebases; adopt tabs or a set number of spaces (ideally tabs) for indenting.
6. Use space consistently to separate operators and delimiters.
7. Be consistent when aligning braces; use a vertically or slanted style.

8. Avoid deep nested conditionals. - Max 3 in player boat placement, 4 is seen as a soft limit
10. Keep variable lifetimes and scope as short and as small as possible. -> doesn't apply to constants, all others are reasonably placed
11. Avoid multipurpose functions and variables. (maybe remove this one)
12. Conserve system resources. -> Use of pointers is handled appropriately, headers are all included appropriately, stupid clear screen function has no other use. Methods in std namespace are all called individually. Single use methods were kept in local scope, multi-use ones were called globally to reduce repetition 
13. Minimise forced type conversion, coercion, or casting. -> only use stoi which is valid, char directly maps to int using ASCII, no explicit casting 
14. Know and test your code: adopt a personal and rigorous testing strategy; don’t just see it if works - test and fix its limits. -> tested regularly 
15. Test early and often, fail fast and resolve effectively. Failed often 

### b. Phase 1 development: tasks, code review and changes (linked to 1d,1e).





Phase 1 development consisted of wider helper functions that dealt with output, input and file parsing and implementing polymorphism. 
Considered how current code state would affect future development during review. 

Initial structure of many classes changed. Initially over-relied on pointers, but scaled their uses back to just the abstract player class. Which wasn't originally meant to remain an abstract class.

Refactored during and after a development phase was complete.

Mostly the creation of classes and member functions
### c. ..repeated for each development phase.
#### Phase 2 - Various input and output developments, manipulation of input data
##### Tasks
##### Code Review
##### Changes
#### Phase 3 - Interaction with defined objects, Game loops and implementation 
##### Tasks
##### Code Review
##### Changes

#### phase 4 - Input clear up,  Salvo
##### Tasks
##### Code Review
##### Changes



### d. Phase n development: tasks, code review and changes (linked to 1d,1e).

### e. Ensuring quality through testing and resolving bugs (linked to 1a, 1b, 2a, 2b..2c).

Before I used jira to move anytasks between swimlanes, I always made sure to test each individual feature independently. Because of the modular nature of object oriented programming, this was made quite easy

Completed various tests at the end of each phase of development and before allocating new ones

However, this was not always the case. Due to the modular nature of my object oriented code and its potential for reuse, there were a few occasions where I found myself fixing bugs for features that had passed testing and were considered bug free in previous iterations of my code, when using them in later portions of my program. Almost all instances of this were input related. 

### f. Reflection on key design challenges, innovations and how they were solved (with examples).
There were several design key design challenges that needed to be considered throughout my project. Some of these were identified in advance as I broke the game design problem down into "epic" style tasks and eventually smaller, actionable tasks; and some were discovered as I proceeded with development. In this section I will discuss these design challenges, and the changes I made to my code and initial design to facilitate the solving of these problems. 

One of the challenges I identified as part of my initial design was that of the player class, and the inclusion of an AI player.  I knew that as part of my implementation that there needed to be multiple game modes that pitted human players against AI opponents as well as fellow human players.  When considering this, I did identify that there were many aspects of a battleship game that an AI player shared with a human player, such as the game boards, data structures that stored ship information, and so on. However, the way in which an AI player operates and calculates its way through a game of battleship is, as one would expect, automated. A human player does have the option to automate the same aspects of its game as an AI player, such as placing ships and firing shots. It was the potential for extra functionality and the additional data that this would require, however, that led my initial design (which in this case remained throughout the project) to have the Human Player and AI player as separate data structures, inheriting from a base player class. Another key consideration that drove this decision was differentiating between the game flow of an AI player and a human player. As the automation of the aforementioned tasks in the case of an AI player would happen with minimal input from a user, with validation that occurs inherently without re-entry, whereas a human player can choose between manual and automated tasks; with manual selections requiring various levels of validation and parsing to ensure any input or selection is valid. This also affected the overall output of the program to the screen as well and would impact which menus and UI elements could be seen and interacted with depending on the type of player. For example, a human player would receive a menu with various options when placing boats onto their boards during a game setup, whereas an AI player would skip to the point after their boats have been placed, with no options visible and no input taken. 

One design challenge that arose as a result of this decision however, was that when creating a new game of indeterminable type, the game itself would not inherently know which type of player would be present, despite our expectations as users to have specific instances of each type of player based on the menu selection. Because of this, I couldn't just instantiate multiple explicit instances of each player class regardless of game type, as this would be wasteful for system resources and would introduce unneeded repetition. Instead, I chose to adopt runtime polymorphism in order to achieve this through this use of pointers to the player base class, which later during my implementation became an abstract class. By utilising this method, I was able to create generate specific instances of AI and Human players as and when they were needed, according to game type. In addition, I would be able to access specific functionality for each player type and through my implemented isHuman function() (which was implemented polymorphically for each derived class, and was virtual in my base class) was able to identify each type of player. The code for this can be seen below.
```
Player* Game::generatePlayers(int selection, int index) {
  //Player 1 will always be human unless its AI vs AI
  if (index == 0 && (selection % 3 != 0)) {
    return new HumanPlayer;
  }
  else if (index == 0) {
    return new AIPlayer(index);
  }

  //Player 2 will be an AI unless its a multiplayer game 
  if (index == 1 && (selection != 2 && selection != 5 && selection != 8)){
    return new AIPlayer(index);
  }
  else if (index == 1) {
    return new HumanPlayer;
  }

} 
```
This decision in itself created its own design challenge from a programming perspective, which I subverted and managed through knowledge of the problem I was trying to solve (the creation of a game of battleship) and prior programming experience. The design challenge related to the use of pointers and the potential for memory leaks when not releasing allocated dynamic memory, which would waste precious system resources and could eventually bottleneck the program during runtime if left unchecked. This was managed by using C++'s delete keyword to deallocate the memory reserved for player objects whenever a game ends. Since Player class instances are members of my Game class, their lifetime is directly tied to the scope of my Game class instance, and all that needed to be done was clear up any memory allocated as a result of my use of pointers at the point of which the game instance is destroyed. 

In the end though, I didn't end up taking this implementation of pointers and runtime polymorphism as far as I could have, where more complex implementations, such as the inclusion of a more sophisticated ship targeting algorithm for AI players, would have been beneficial and made logical sense in terms of design. My initial design ideas had these extended  pieces of functionality in mind, but I ultimately never got around to implementing them. Regardless, my final class designs are well equipped for any future implementations. 

Another design challenge I identified early on was the storing of each player's boards (both the ship and targeting board) and subsequently displaying them. The boards themselves are arranged in a grid across two axis with specific reference notations assigned to each (A number for the row and letter for the column). From the beginning I strongly believed that this reference notation lent itself quite well to a two dimensional array, as two separate locations in both the x and y axis needed to be specified as standard. These could then be directly mapped to locations in each of the arrays. An important point when considering this method was whether the notation was ascending or descending in the Y axis, as the former would make it considerably more difficult to map reference values to specific array nodes, thankfully, the Y axis is descending in a game of battleship. With a data structure chosen, I then needed to decide what each individual array node represented. The board itself was to be represented in a class of its own which housed the aforementioned array. It therefore made sense that each node would represent an individual space, or coordinate on the board. This was represented by my user-defined Space type, the implementation of which can be seen below:
```
struct Space {

  Space(int col, int row)
  {
    location.colPos = col;
    location.rowPos = row;
    outputValue = symbol_Square;
    status = SpaceState::Inactive;
    outputColour = text_Colour_Sky_Blue;
  };

  Coordinates location;
  SpaceState status;
  string outputValue;
  string outputColour;
};
``` 
This combination of defined data structures wouldn't just exist conceptually. Another key consideration I needed to take into account was displaying an appropriate output value. This was appropriately captured in addition to an output colour in my Space struct. With the above considerations regarding notation also taken into account, the only hurdle was utilising a loop to output value assigned to each space. In the interest of making the output more appealing, this was done in tandem with other values being output to give the impression of a grid. This includes labelled axis with coordinate cell references, and a series of vertical and horizontal lines to separate each space. This was achieved with various Unicode characters, which would change depending on the position in the loop and output display. 


Converting input and output values to and from letters was also a design challenge identified in the early stages of development. From the offset, I knew there would be a disconnect between the required input of a board coordinate (i.e. A1) and its appropriate position in a relevant data structure (which in my case was the 2D array detailed above), which would require converting a letter into an appropriate number to access the relevant column. Similarly, converting to a letter was required when displaying positions that are represented on the player's boards, in order to reflect the actual playable area. This can be seen on the on the labelled Y axis of the boards, and when viewing boat statuses when placing boats. 

Both solutions to each of these problems exploit ASCII character values in C++'s char type, which directly correlate to integer values 0 to 255. In the case of converting to a letter, the value used to represent each character starts at 'A' (integer value 65) and the remainder of a division between the number to convert and the length of the alphabet (26) is added to the character value. The resulting character is added to a cumulative string and repeated by dividing the number to convert by 26 and repeating while the value is positive. This approach allows for any number to be converted in to what is essentially a base 26 value, and is highly reusable beyond the needs of the project, since essentially any number can be converted into its letter equivalent.

The same applies to the 










Conversion to and from letters 
Converting to a letter was required for output purposed to reflect actual playable area
Converting from a letter was required to access specific data structure instances 


## 3. Evaluation (academic standard: distinction level detail: section required for distinction) – 10%
### a. Analysis with embedded examples of key code refactoring, reuse, smells.
#### Distinction: Statements with deep justifications and discussions

#### Refactoring
Throughout the course of my battleship project, I made a conscious effort to refactor my code at various intervals, 

Input function
Setup cases
Ui revisions
Conversion to letter





#### Reuse 
Purposefully using runtime polymorphism for the player classes to prevent major code reuse. Player related game functionality kept in the game class to prevent reuse, with specific instances for each type being placed into helper functions, limiting code changes to a single location and centralises any changes that needed to be made. 

Derived player classes (AI Player and Human Player), 

#### Smells

Refrained from using string literals and "magic" values where possible. Kept coupling low and cohesion high. 

That being said, some less impactful aspects of coupling made its way into my code by default, such as a reliance on external modules. This, ultimately, was unavoidable, regardless of how well encapsulated it was, or if it was deferred to globally available helper functions (or design patterns such as singletons). And while it is relatively less impactful than other types of coupling, it was still present in my code. 

Kept a consistent naming convention throughout with an m prefix for each member variable. This allowed me to easily identify each variable and realise its purpose within an object, which also further contributed to the readability of my code. 

~~^^This is a really good example of the kind of writing style he's looking for~~

Potential "shotgun surgery" in places where multiple things needed to change. In reality, due to my experience with the language and object oriented design thinking, changes to my initial design required changes in multiple places to facilitate the flow of data and to fix bugs. Additionally, I made use of many globally available functions 

Coupling?



### b. Implementation and effective use of ‘advanced’ programming principles (with examples).
In order to demonstrate my abilities as a programmer, I made use of a number of advanced programming principles which not only contributed to the quality of my code, but also improved the logic and flow of the developed program by taking advantage of my chosen language, C++ and its specialist features. 

Chief among the advanced programming principles was that of object orientation, which is widely considered to be one of the end goals of C++, as Stroustrup developed C++ with object orientation in mind (Vartanian, 2022). However, it is argued that C++ lacks the purity of an object oriented language such as Java (Why C++ is partially Object Oriented Language? - GeeksforGeeks, 2017), as it is not solely reliant on objects in order to implement basic functionality and is deemed a multi-paradigm language as such. That being said, the inclusion of the option to program in an object oriented fashion, along with it being a popular paradigm to follow, illustrates that C++ lends itself well to the principle. 

In the case of my project, I had object orientation in mind from the very beginning, which can be seen in the pattern that emerged through my file structure and code. ![File structure used, many containing the definitions and implementations of individual classes](Images/1762c6649af7768f1a50b6e39cfebd9b.png) 

This essentially decomposed each aspect of the game of battleship into its own set of objects. Such as the concept of the game itself and its associated features and attributes, seen below: 

![Example of "Game" class, containing associated functions and member variables](Images/65bf4eca3db40f8c625272c71c367f4d.png) 


This not only lent itself well to development of a game such as this, but also presented an oppurtunity to encapsulate each of these objects in C++'s supported classes, which allowed myself to consider the separate functionality and associated data of each object. While many of these considerations were pondered well in advance of development commencing, the act of implementing these objects according to a premeditated design, while keeping in line with C++ explicit rules, was a challenge in of itself. Due to my lack of professional experience with C++ as a language, many aspects of my initial design changed over the course of development. Regardless, I managed to stick to object orientation as a paradigm, even if I strayed from my initial design.

An important consideration, in keeping with object oriented design principles, was the relationship between objects. These were an aspect of my initial design that remained constant throughout the development of my project. During my initial designs, I specified the relationships between each associated object. For example, in my UML diagram, I made note of the fact that each "game" class instance has exactly two "players" class instances associated with a composition relationship; that is, a relationship which is wholly reliant on the lifetime of the "game" object, as without it, the associated players would not exist (IBM Docs, 2021). Implementing this in my program was relatively simple, my game class needed to be setup with two players as data members. In the context of access modifiers, the decision was already laid out in my UML design, but was ultimately inconsequential when describing and implementing the relationship between the game and player classes in this instance. 

Deeper considerations did need to be given however, for variations of my player class, and the way in which data was shared between them. This relationship, inheritence, can be directly implemented and described in C++ when creating a class that derrives from a "base" class. In this case, I had a base "player" class which two subclasses, "AIPlayer" and "HumanPlayer", inherited from. These were created to fulfil functionality specific to each type of player that was featured in my game project. For example, a HumanPlayer class instance is able to directly set its name upon creation, based on user input. This required its own function, "declarePlayerName", which is not present in the AIPlayer class, despite both derived player classes inheriting the mPlayerName variable. Where the implementation differs between classes, is that an AIPlayer will always have its name set to "Player" by default, with no need to set a custom name. This is a design decision that I came up with based on implementations in other games, where computer controlled players would have static, generic names, which I felt was suitable for this project. Depending on the type of inheritence I specified, this would affect the two derived class's access to variables and functions in the base class. For the sake of my project, I chose public inheritence, which gave my inherited classes the same level of access as my base class to functions and variables as they were initially defined. This level of access was chosen as each implementation of an "AIPlayer" or "HumanPlayer" still needed access to attributes such as a player name, battleship game boards, and ships used for gameplay. In addition, this helped to prevent code reuse, as these attributes would not need to be repeated in the derived classes. Furthermore, my implementation did not call for a greater level of security that the other access modifiers, private and protected, would provide, nor did any data in the base class need to be obscured. 

Functions in my base class were publicly available for use where instances of "player" or derived "player" objects were found. This was done for ease of access, while at the same time not allowing direct access to member variables, which were defined as private. Where I wanted my implementation of these functions to differ from the base class, I had to exhibit polymorphism. This was mostly implemented where common functionality from the base class would not apply to aspects of the derived classes. For example, the way in which each type of player places their ships on the game boards is not always identical, as an AI player will always do so randomly, whereas a Human player is able to choose between manual and various levels of automatic placement. For this purpose, I created a polymorpic function in the HumanPlayer derived class to account for this extra functionality. The "virtual" c++ keyword was utilised alongside the same function definition in the base class to account for this variance, and therefore, whenever a human player opts for the manual of boat placement, the correct version of the function is used for Human players, rather than the one declared in the base class. 

This was done to avoid code repetition and ensure that any early binding by the compiler did not occur, which would result in the wrong function implementation being called. Bugs caused by early binding can be hard to debug, so I opted to avoid encountering them altogether. 

Additionally, standard polymorphism combined with user defined objects allowed for behaviour specific to one of the derived player classes to be defined within the constructor, in addition to the standard initialisation provided by the base class. 

In the context of C++, when one refers to Polymorphism, it is often assumed that they are referring to the concept of Polymorphism with late binding. (Eckel and Allison, 2004) believe that the term should only be used to refer to this type of polymorphism, commonly known as runtime polymorphism. 

The benefits of runtime polymorphism are thus; to be able to invoke the functions of objects at runtime, rather than compile time. This means that the type of the object itself doesn't even need to be known in order to invoke the function, due to the inclusion of a base class pointer. This provides a level of flexibility in exchange for a slight performance hit, especially in the case of this project, where this type of polymorphism is only achieved once per game object lifetime. 

I felt this lent itself quite well to my project since I had multiple player class types included as part of my initial design, and utilising runtime polymorphism would enable me to make specific calls to member functions of those derived classes without including any extra code, or explicitly having to define instances of those object types. The inclusion of this 'advanced' feature may not have been used to its full potential from my perspective, but I still believe that its inclusion and implementation are valid.

Implementing runtime polymorphism necessitated the use of dynamic memory allocation and pointers. This, at face value, betrayed one of the 15 standards in not conserving system resources, and opened my program up to potentially unwanted behaviour via memory leaks, which can be dangerous for a program. However, relatively speaking, my player classes have quite a minimal memory impact and overall size in bytes. In addition, I was very much aware of the scope of any player objects created, as outlined in my UML diagram, which noted that they are intrinsically tied to the lifetime of my Game class object. Therefore, so long as appropriate measures were taken to release the allocated memory upon each Game object's destruction, memory leaks would be prevented and system resources would be conserved. I would then be able to reap the benefits of dynamic memory allocation and runtime polymorphism without fear of memory based issues within my project. 

I also utilised various IO features throughout my project. The regex header and type allowed for the deferral of comprehensive input parsing and error handling. This was especially useful for complex input scenarios such as manual boat placement and firing, where several other conditions, such as valid board placement needed to also be assessed. Iomanip was another useful header was utilised to manipulate various output strings, and contributed to the structure of UI elements such as the boat placement status summary and most importantly, the game boards themselves. Functionality such as setw was used to set the width of an output stream, which was used in tandem with left and right modifiers to affect the alignment. This contributed to a visually appealing and uniform output display that was used alongside standard output methods. 

I also used the fstream header's functionality to read inputs from a file. From here, I had to parse the file according to its specific format in order to create instances of Ship and Board objects for each player. This required me to take advantage of various operations built into the string library, some of which I employed in my own functions, such as this one below which removes leading and trailing spaces from a string by utilising the find_first_not_of and find_last_not_of functions. 
```
string removeLeadTrailSpaces(string stringToChange)
{
  //find the first and last instance of anything that generates whitespace
	size_t firstChar = stringToChange.find_first_not_of(" \t\v\r\n"); 
	size_t lastChar = stringToChange.find_last_not_of(" \t\v\r\n");
	stringToChange = stringToChange.substr(firstChar, lastChar - firstChar + 1);
  return stringToChange;
}
```
Using this function allowed me to take a split string and sanitize it for conversion into non string types; in this case, to an integer using the stoi function, also defined in the string library. I made use of this function liberally throughout development, mostly to handle various types of user input. 

The notable design patterns I utilised for this project were that of finite state machines (FSM) and factory methods. I believed the FSM pattern lent itself well to the project since there were various objects, such as boats, spaces and the game itself that have mutable states of being and appropriate actions to go along with them. Said states were useful to track, as it gives an idea for the overall state of the program. It also assists with debugging by allowing us to associate various states with expected behaviour.  This is a commonly used pattern in game development (Berglund, 2017), among other applications. My sole factory method is used to create derived instances of the Player class with the generatePlayers() function, which can be seen below:
```
Player* Game::generatePlayers(int selection, int index)
{
  //Player 1 will always be human unless its AI vs AI
  if (index == 0 && (selection % 3 != 0)) {
    return new HumanPlayer;
  }
  else if (index == 0) {
    return new AIPlayer(index);
  }

  //Player 2 will be an AI unless its a multiplayer game 
  if (index == 1 && (selection != 2 && selection != 5 && selection != 8)){
    return new AIPlayer(index);
  }
  else if (index == 1) {
    return new HumanPlayer;
  }
  
} 
```
I found this pattern useful as a specific instance of a game always contains two players, but we don't know if they are human or AI controlled. I avoided the singleton pattern as I believed it would increase the level of common coupling between classes in my system. I did widely utilise global variables within my program, but these In addition, singletons break the single responsibility principle and are hard to debug and test due to their immutable state (Densmore, 2004). 



### c. Features showcase and embedded innovations (with examples) - opportunity to ‘highlight’ best bits.

Conversion of letters to numbers and vice versa
Relevant state machines
Grouping of common values into user defined structs
Runtime polymorphism and use of pointers (creation of dynamic objects)
Recursive functions
Generate players

### d. Improved algorithms – research, design, implementation, and tested confirmation (with examples).

File parser
Conversion of numbers to letters
Conversion of letters to numbers
Pure check input function (with regex)



### e. Reflective review, opportunities to improve and continued professional development.

Overall, I believe my implementation of the chosen problem was a solid attempt of reasonable complexity that lacked an exceptional level of complexity, which could be improved upon in the future. As it stands, my game has two game modes with 3 separate player configurations (Player vs Player, Player vs AI, AI vs AI), I believe to reach the desired level of exceptional complexity, the inclusion of another game mode (with the included player configurations) would be required. My code exhibits many building blocks for features that could be further developed. For example, my AIPlayer polymorphic class makes little use of its polymorphic state beyond being used to identify whether or not a player is a human player via a polymorphed function. However, this polymorphic state could be used to instead create truly unique functionality for the AI Player class such as an improved targeting function, rather than the one utilised in the base player class. Additional member variables unique to the AI player class could also be included in these in order to better facilitate these additions. 

In many cases when designing initially, I found myself attempting to design a system that was too large and going beyond a level of complexity that was appropriate for that stage of development. In essence, I was attempting to do too much at once. This could be seen in earlier versions of my code, that included menu options, input cases, functions and enumeration values for game modes and functionality that were never implemented. Examples of this can be seen below:

My rationale for approaching the project in this way was to avoid creating initial versions that were too hard to refactor during subsequent stages of development. In the end, many of my initial designs needed to be refactored anyway and many new functions were created in my classes during later stages of development. Additionally, in a given phase of development my code changed in many different places, so said refactoring of previously developed modules would have come naturally as part of development. To improve in the future, I would follow development phases more stringently, and focus on a given task at hand. 

I believe I have a good understanding of C++'s ability to facilitate OOP, but I often find it difficult to think in an object oriented way and adhere to the expectations of an object oriented program. Specifically, I struggle to apply object oriented thinking on an object-by-object basis, going with a general rule of thumb rather than picking the best level of encapsulation for a given situation. I believe this affected my ability to create meaningful and effective pure functions within my classes. For example, the use of getters and setters are believed by many to be an anti-pattern (Spajic, 2019), which break encapsulation. Some even believe they shouldn't be used at all, outside of examples which make perfect contextual sense to an object (Bugayenko, 2014). There are examples within my code where the inclusion of getters and setters make sense not only contextually, but functionally as well. Such as in my boat class and player class respectively:
```
BoatStatus Ship::reportStatus() 
{
  return mStatus;
}
```
```
string Player::sayName()
{
  return mPlayerName;
}
```
In these contexts, both of these objects as defined in a real-world scenario are able to do both of these things, either implicitly or explicitly. 

I also made effective use of a private function in my HumanPlayer class, which had the right level of access for its purpose and is only called from a constructor. This can be seen below: 
```
string HumanPlayer::declarePlayerName()
{
   //temporary string to store value, don't want to put into member variable without checking it's valid
  ui_saveCursorPos();
    //check all is ok using input parser()
  string playerAlias = getLineString(regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters: ");
  

  return playerAlias;
}
```

However, over the course of development, my Board class gained many getter and setter functions when it likely would have just made sense to make the appropriate member variables public. This is especially true for the spaces member variable, which make up the spaces found on the game board in a 2D array. 

The same applies to my Ship class, which also has individual accessor functions that return the various values of private member variables. If we follow the principles followed by (Bugayenko, 2014), then it makes no sense for a ship to be able to report its size, as it is not typically an action that a ship can do. Conversely, functions to report a status and location would make sense, as these are things that a real world ship object could actively track. 
```
BoatStatus Ship::reportStatus() 
{
  return mStatus;
}

vector <Coordinates> Ship::reportLocation()
{
  return mLocations;
}

int Ship::reportSize() 
{
  return mSize;
}
```

When I constructed my initial design, I had a different, but misplaced understanding of the level of access that derived classes had to base class variables when inheriting publicly. This meant that I had designed my system and derived classes to manipulate data it did not have access to, giving the AIPlayer and HumanPlayer classes a heightened sense of importance. 

 and my understanding of derived classes access to base class variables, while still attempting to maintain a level of encapsulation. In many cases, I worked around these by including functions in the base class to relieve any potential coupling between classes and to maintain encapsulation, but in doing so I somewhat undermined my use of runtime polymorphism, relegating my dynamic derived classes to variations on functions that took input or generated values to perform a task, such as firing a torpedo or placing a boat. This is not to say that my application of this feature was invalid, but rather 

My background as a programmer revolved around repetition of many of the basic aspects of C++ which resulted programming in a procedural and sometimes functional way. Through targeted personal development in the future, I could endeavour to become a multi-paradigm polyglot programmer. Thinking in an object oriented way would likely come with practice, too. 

For the sake of this project, which very much lent itself well to object oriented design and thinking, I found it quite intuitive to create UML notation and diagrams and was able to think and create what I believed to be quite a solid initial system, with correct relationships and instances between each object. While few aspects of my initial design remained intact by the end of the project, the overall relationships between and levels of access within each class remained mostly the same, without a need to create any additional classes. I would like to try and apply this thinking to a more unorthodox system at some point in the future, to see if I can apply the same logic and reasoning to another project. 

Many advanced aspects of the language such as multithreading, templates and other, more efficient aspects of the standard template library went unused in my project. While this simply could have been an instance of it not being suitable for the project, I felt as if my understanding of these aspects was not deep enough to be able to utilise or apply these useful tools effectively. For example, template types and generic functions would have worked well alongside my many user defined types and classes, as I would have been able to implement them without having to explicitly specify a type and further bring down code reuse. Although, in this case, my user-defined data structures would have needed refactoring to work with these generic types. Any implementation of multithreading would have put my program at risk of unexpected behaviour due to my reliance on console output functions, which are not thread-safe, but could have provided aesthetic benefits through the use of wait() to simulate loading and automated functionality. 

While I was able to follow a standard and consistent development process throughout my project. I had difficulty seeing the bigger picture when planning and decomposing the various tasks I derived from the "epics" I identified initially. While I was able to identify a set of smaller task that I could reasonably action, there were numerous times that I did not take into account other various associated tasks, which made it tough to estimate a time to completion for each task and subsequently increased the scope of each set of features beyond what I initially believed. An example of this was during phases 2 & 3 of development when implementing boat placement and firing functions. While I had taken into account the aforementioned functions as part of my player classes, there were aspects such as resetting and manipulating the UI, which I forgot to consider. While this could be considered an honest mistake, since there are many globally available utility functions which are separate from my classes  and therefore went these aspects went unconsidered as part of my initial design and discovery, it still impacted the amount of time it took to complete what I had envisioned as a significantly smaller set of tasks.

Such mistakes would greatly impact the timescales and scope of a project in a professional environment. Although, depending on the size of a team in a professional environment, the act of decomposition and discovering the solution to a problem could be the responsibility of other members of the development team, for example: business analysts and senior programmers. Regardless, it is a vital skill and one that I should consider refining in order to continually improve and develop as a professional.

In conclusion, while my implementation lacked an outstandingly deep level of complexity and does take full advantage of some of the advanced features it implements, it represents a solid attempt at implementing and solving the problem it chooses to tackle. With more experience programming at this level of complexity and within a suitable professional environment, I will hopefully be able to expand my knowledge of object oriented programming and design methods and confidently be able to design and implement a deep and complex program from end to end. 


## References
- Vartanian, E., 2022. Is C++ an object-oriented programming language?. [online] Educative: Interactive Courses for Software Developers. Available at: <https://www.educative.io/blog/is-cpp-object-oriented-programming-language>
- GeeksforGeeks. 2017. Why C++ is partially Object Oriented Language? - GeeksforGeeks. [online] Available at: <https://www.geeksforgeeks.org/c-partially-object-oriented-language/>
- Ibm.com. 2021. IBM Docs. [online] Available at: <https://www.ibm.com/docs/en/rational-soft-arch/9.5?topic=diagrams-relationships-in-class>
- Eckel, B. and Allison, C., 2004. Thinking in C++. Upper Saddle River, N.J.: Prentice Hall, p.716.
- Spajic, Z., 2019. _Getter, Setter, Never? - madewithlove_. [online] madewithlove. Available at: <https://madewithlove.com/blog/software-engineering/getter-setter-never/>
- Bugayenko, Y., 2014. _Getters/Setters. Evil. Period._. [online] Yegor256.com. Available at: <https://www.yegor256.com/2014/09/16/getters-and-setters-are-evil.html> 
- Berglund, C., 2017. _Designing a simple game AI using Finite State Machines_. [online] Game Developer. Available at: <https://www.gamedeveloper.com/programming/designing-a-simple-game-ai-using-finite-state-machines>
- Densmore, S., 2004. _Why Singletons are Evil_. [online] Docs.microsoft.com. Available at: <https://docs.microsoft.com/en-us/archive/blogs/scottdensmore/why-singletons-are-evil> 
- Stroustrup, B., 2019. _Stroustrup: C++ Style and Technique FAQ_. [online] Stroustrup.com. Available at: <https://www.stroustrup.com/bs_faq2.html> 

