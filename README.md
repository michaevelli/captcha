## Captcha

Crack numeric captcha. Approximately 90% success rate per digit  
"captcha" folder contains example captchas  
"digit" folder contains example digits  
"more" folder contains further digits which was not used to generate the data used to analyse  
Analysis done by calculating properties of individual digits, then comparing values to the standard deviation and choosing the most matching digits  
Properties include  
..* Horizontal Balance
..* Vertical Balance
..* Tallness
..* Density
..* Holes
..* Hole Fraction
..* Hole Horizontal Balance
..* Hole vertical Balance
..* Hole Tallness
..* Horizontal Intersections through center
..* Vertical Intersections through center
..* Amount of whitespace Left of digit
..* Density of Halves
..* Density of Quadrants

UNSW COMP1511 17s1 ass1

## Usage
To crack digit
```bash
$ gcc arrvalue.c attributes.c bounding_box.c captcha.c copy_pixels.c crack_digit.c  fakehole.c floodfill.c points.c print_image.c read_pbm.c -o crack_digit -lm
$ ./crack_digit digit/0_00.pbm
0
```
To crack captcha
```bash
$ gcc arrvalue.c attributes.c bounding_box.c captcha.c copy_pixels.c crack_captcha.c  fakehole.c floodfill.c points.c print_image.c read_pbm.c -o crack_captcha -lm
$ ./crack_captcha captcha/0008.pbm
0008
```

## Installation
Compile with `gcc arrvalue.c attributes.c bounding_box.c captcha.c copy_pixels.c crack_digit.c  fakehole.c floodfill.c points.c print_image.c read_pbm.c -o crack_digit -lm` for cracking digits.  
Compile with `gcc arrvalue.c attributes.c bounding_box.c captcha.c copy_pixels.c crack_captcha.c  fakehole.c floodfill.c points.c print_image.c read_pbm.c -o crack_captcha -lm` for cracking captchas.

## Contributing
Do as you wish, I suppose

## License
MIT