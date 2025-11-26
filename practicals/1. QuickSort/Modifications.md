# Critical Thinking and Profiling Tasks

After implementing Quick Sort and generating a gprof report, reflect on the following:

1. The gprof result shows two key parts - the flat profile plus the call graph. What’s revealed by each part about how your code runs? You could combine them to spot slowdowns - here's how it works.

2. To get useful profiling info, try running the program using either a tiny input - say, 10 items - or a much bigger one, like 50,000. Because when inputs are super small, timing differences can be too tight to measure well. That’s where tools like gprof might give misleading numbers or miss key details. Tiny runs often don’t reflect real-world behavior, so performance stats could seem off. Longer workloads tend to expose actual bottlenecks more clearly.

3. Try guessing how deep Quick Sort goes by looking at its call pattern. What happens to that pattern if the data’s sorted compared to mixed up?

4. Imagine running gprof on two Quick Sort types - one picks the last item as pivot, the other a random one. You’d check how much time each spends inside sorting functions. Look at where most cycles go - maybe recursion depth changes things. Focus on seconds per function, call counts, maybe memory isn’t key here. See if one version hits hotspots more than the other. Compare flat profile numbers side by side. Even small timing shifts can hint at big differences under load.

5. The flat layout displays "cumulative seconds" along with "self seconds." How do these numbers differ from each other? When improving a recursive method such as quickSort, which value holds greater importance?

6. If you start the same program again and again using identical input, does gprof give matching time numbers each round? Not really - small shifts in system activity, memory setup, or background tasks can tweak the outcome every single time.

