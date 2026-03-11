# Philosophers

![Languages](https://img.shields.io/badge/C-84.9%25-blue.svg) ![Languages](https://img.shields.io/badge/Makefile-15.1%25-yellow.svg)

## Overview

The **Philosophers** project is a C language implementation inspired by the classic _Dining Philosophers_ problem—an example often used in computer science for illustrating synchronization, concurrency, and deadlock avoidance.

## Language Composition

- **C (84.9%)**: Core logic, thread management, synchronization.
- **Makefile (15.1%)**: Build instructions and project automation.

## Problem Statement

The Dining Philosophers problem models a scenario where several philosophers sit at a table with forks between them. Each philosopher alternates between thinking and eating. To eat, a philosopher must acquire both adjacent forks. The challenge is to design a system that prevents deadlocks and ensures that every philosopher can eat and think without starvation.

## Features

- Thread-based simulation of philosophers’ actions.
- Solutions for preventing deadlocks and starvation.
- Customizable simulation parameters (number of philosophers, timings).
- Clean, modular C codebase.

## Build & Run

### Requirements

- GCC or compatible C compiler
- Make

### Build

```bash
make
```

### Usage

```bash
./philosophers <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers at the table
- `time_to_die`: Time (ms) before a philosopher dies if not eating
- `time_to_eat`: Eating duration (ms)
- `time_to_sleep`: Sleeping duration (ms)
- `[number_of_times_each_philosopher_must_eat]`: (Optional) simulation stops when all have eaten this many times

### Example

```bash
./philosophers 5 800 200 200
```

## Project Structure

- `src/` — C source files for the simulation logic
- `include/` — Header files
- `Makefile` — Build automation

## Contributing

Feel free to fork, open issues, or submit PRs for improvements and bug fixes.

## License

This project follows the license provided in the repository.

## Author

- [Denionline](https://github.com/Denionline)