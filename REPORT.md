# CST276SRS02  

Date Validation Strategy/Template Method  

Name: Mark Hultin  

---
Issues:  No issues at this time.


Notes:  

Implemented the canonical GoF Strategy and GoF Template Method patterns.

Implemented the DateI18NEnum project and extended it for the YDM format. 
The Format Enum class and switch statement were modified to support the YDM format.

Implemented the DateI18N project with the GoF Strategy method and extended it for the YDM format.
A fourth concrete class was created to support the YDM format.
I failed to maintain the interface for the Strategy method, due to the need for the verification members
 in the concrete class. The Template Method would have been a perfect way to maintain the interface of the
 Strategy interface and avoid duplication of the string manipulation and validation code in the concrete classes.

#Enum Class pro/con
-Pros:
--Few files in the code base
--Easy to follow
-Cons:
--Switch statement modification can cause unexpect issues, such as missing breaks
--Updates to an Enum Class may impact many locations in code

#Strategy Method pro/con
-Pros:
--Easy to duplicate existing strategies for new strategies
--
-Cons:
--Increases the number of files in the solution
--Potential for code duplication if the Template Method is not also implemented

UML Class diagrams for DateI18N and DateI18NEnum were created in Visio and saved as a single PDF.
###

