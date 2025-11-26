
x = var('x')  
f(x) = sin(x) + 0.5*x


p = plot(f, (x, -2*pi, 2*pi), color='blue', thickness=2, legend_label='f(x) = sin(x) + 0.5x')


show(p)

