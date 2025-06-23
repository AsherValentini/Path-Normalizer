# PathNormalizer

## “Normalize and resolve relative directory paths like a shell would.”

## Problem Summary:

You're building a path resolver module, similar to how a shell or OS normalizes file paths. Given input strings representing file paths that may include ".", "..", and redundant slashes, your job is to normalize them.

## Example Input:

std::vector<std::string> paths = {
  "/usr/bin/../bin/./scripts/../",
  "/home/./user/../user2/docs/../pics/"
};

## Expected Output:

[
  "/usr/bin/",
  "/home/user2/pics/"
]
## Core Concepts:

    Stack-based processing

    Tokenization via / split

    Handling "." (current dir) and ".." (parent dir)

    Edge cases (leading /, trailing /, multiple slashes)

## Skills You’ll Practice:

Concept	How It's Involved
Stack usage	Track directory structure as you parse
String tokenization	Split paths on /, clean up parts
Filesystem modeling	Simulates shell path resolution logic
Modular design	You'll build a PathNormalizer class with a .normalize() API

## Estimated Time:

### Medium (45–60 min)
