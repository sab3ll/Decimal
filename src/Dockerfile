FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y gcc curl git make check valgrind gcovr clang-format xdg-utils links vim cppcheck zsh doxygen python3 nodejs
RUN chsh -s /usr/bin/zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

CMD ["/usr/bin/zsh"]
