#!/bin/bash

readonly PROJECT=s21_decimal

docker run -it --name $PROJECT --rm -v $(pwd):/app -w /app school21 zsh
