# Read Me #

## How it works ##
objects are stored as structs with pointers to:
	1. a struct that holds its properties
	2. a struct that holds its methods

A subclass's prop struct _contains_ the struct of its super class at the very begining of the memory block allocated to it. 

`
struct Person_Properties{
	Properties super;
	char * name;
};
`

This allows for easy inheritance and casting. Simply casting `Person_Properties * p` to `(Properties *)p` provides easy access to the properties of the super class. 

I have implemented method inheritance in a similar way. 

Polymorphism is implemented as well. I replace pointers to functions in the super method struct with new methods to override them and provide polymorphism.

## Motivation ##
I wanted to learn how object-oriented programming was implemented in C. I enjoy deriving complex things on my own to really understand the inner-workings.