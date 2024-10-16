
### Fract'ol - A Fractal Exploration Project

2. Navigate to the project directory and compile the program using the provided `Makefile`:
   ```bash
   cd fractol
   make
   ```

### Usage

Run the `fractol` program with the desired fractal type and optional parameters:

```bash
./fractol <fractal_type> [options]
```

#### Example:

```bash
./fractol mandelbrot
./fractol julia -param1 -param2
```

- **`<fractal_type>`**: Specifies the fractal to display (e.g., `mandelbrot`, `julia`).
- **Options**: Additional rendering options can be passed for Julia set parameters or color effects.

### Controls

- **Zoom**: Scroll the mouse wheel to zoom in and out.
- **Close Program**: Press `ESC` or click the window close button to exit cleanly.

## Project Structure

- **Makefile**: Builds and manages the project files with commands:
  - `make`: Compiles the project.
  - `make clean`: Cleans up object files.
  - `make fclean`: Removes all generated files.
  - `make re`: Recompiles the project.
- **Source Files (`*.c` and `*.h`)**: Contains all C code for fractal generation, event handling, and graphical display.

## Technical Highlights

- **Event Handling**: Smoothly handles keyboard and mouse input, including zoom and exit events.
- **Fractal Generation**: Renders Mandelbrot and Julia fractals using complex number calculations.
- **Color Depth**: Adds color variations to represent depth within fractals for a visually engaging experience.

## Requirements

- **External Functions**: Uses functions from the math library (`-lm`), MiniLibX, and custom library functions (`libft`).
- **Global Variables**: The project avoids global variables to ensure better modularity and maintainability.

## Error Handling

- If an invalid parameter is provided, Fract'ol will display a list of available parameters and exit gracefully.
- Handles memory allocation errors and other runtime issues with appropriate messages.

## License

This project is for educational and practice purposes. Feel free to explore, modify, and use it as a learning resource!

---

Explore, experiment, and enjoy the beauty of fractals with Fract'ol! ! 😊

```

```
