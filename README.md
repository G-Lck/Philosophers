# Philosophers

> *This project has been created as part of the 42 curriculum by glucken*

---

## Description

We have **N philosophers**, they have to eat for a certain time, sleep for a certain time and think. If there is more than time_to_die between 2 meals, they die. When a philosopher is dead, the simulation stops. They need **two forks** to eat and there is only one fork between each philosopher, so they have to eat asynchronously to optimise the use of forks and avoid dying.

Each philosopher is a **thread**, another thread is created for a monkey, he is here to check if someone is dead of starvation or if everyone has eaten enough.

### Structure

- A philo structure is created for each philosopher and they all share a common structure info, with shared information and a part of the structure fork.
- A **mutex** is created for each fork, also for the printer (print) and the coffin (dying) — only one philo dies and the simulation stops. In fact dying protects should_stop, which is used if someone is dead and if everybody has eaten enough.
- There is **no protection** for last_meal and n_meal because there is only one writer and one reader. Maybe if it took time to change them (like a very long function) it could make sense to use a mutex, but I don't think so here.

### Heads up

Be careful when you read the code: when we talk about even and odd philos, they begin at **0**, but the number of the philo printed is offset by **+1**.

### Optimisations

1. **Fork order** — All even philos begin by taking the right fork and all odd ones the left fork, in order to not have each philo holding one fork with nothing happening (deadlock avoidance).
2. **Think time for odd counts** — When there is an odd number of philosophers, we add a minimum time to think, corresponding to the time to eat, in order to let the other philosophers eat and avoid starvation.

---

## Instructions

The programme takes the following arguments:

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

The last argument is optional.

As they should avoid dying, at minimum:
- If they are **even** we need max(time_to_eat * 2, time_to_eat + time_to_sleep)
- If they are **odd** we need max(time_to_eat * 3, time_to_eat + time_to_sleep)

Of course a small margin of time should be added on top of that, because thread scheduling and context switching are not instantaneous — the OS needs time to wake up threads and switch between them. The more philosophers there are, the bigger this margin needs to be. Under that, one will die.

### Testing

- To test **memory leaks**, use valgrind.
- To test **data races**, use the option --tool=helgrind.
- To avoid false positives from n_meal and last_meal, the option --suppressions=helgrind.supp with the appropriate file can be used.

---

## Resources

As usual, first a reading of the **man** for each new function. Then:

- This [Medium article](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2) to better understand threads and the use of the functions
- This [video](https://www.youtube.com/watch?v=UGQsvVKwe90) to get started — was really useful
- This [visualiser](https://rom98759.github.io/Philosophers-visualizer/) was a good tool to debug

*No AI has been used for this project except to correct this README.*
