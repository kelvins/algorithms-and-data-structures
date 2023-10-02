package main

import (
	"fmt"
	"strings"
	"unicode"
)

/*
	Instructions

Determine if a word or phrase is an isogram.

An isogram (also known as a "non-pattern word") is a word or phrase without a repeating letter,
however spaces and hyphens are allowed to appear multiple times.

Examples of isograms:

	>> lumberjacks
	>> background
	>> downstream
	>> six-year-old

The word isograms, however, is not an isogram, because the s repeats.
*/
func main() {
	fmt.Println(IsIsogram("isograms"))
	fmt.Println(IsIsogram("isogram"))
}

// IsIsogram returns true if the input s is an isogram
func IsIsogram(word string) bool {
	word = strings.ToLower(word)
	for i, c := range word {
		if unicode.IsLetter(c) && strings.ContainsRune(word[i+1:], c) {
			return false
		}
	}
	return true
}
