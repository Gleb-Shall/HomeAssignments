# BMP Image Processing Lab

**Author:** Gleb Shikunov  
**Student ID:** st128274@student.spbu.ru  
**Course:** Programming in C++  
**Lab:** #1 - Loading and Processing Raster Images

## Description

This project implements a BMP image processing application that performs the following operations:

1. **Load BMP images** - Supports 24-bit and 32-bit color BMP files
2. **Rotate images** - 90° clockwise and counter-clockwise rotation
3. **Apply Gaussian filter** - Smoothing filter for image processing
4. **Save processed images** - Output in BMP format

## Features

- ✅ Memory efficient processing (uses ~100% of data size)
- ✅ Real-time performance (total processing < 15ms)
- ✅ No memory leaks (RAII design)
- ✅ Comprehensive error handling
- ✅ Detailed timing and memory usage reporting
- ✅ Support for both 24-bit and 32-bit BMP files

## Project Structure

```
lab1/
├── main.cpp              # Main application logic
├── WorkWithBMP.h         # BMP processing class header
├── WorkWithBMP.cpp       # BMP processing class implementation
├── Makefile              # Build configuration
├── README.md             # This file
└── *.bmp                 # Sample images and outputs
```

## Build Instructions

### Prerequisites
- C++17 compatible compiler (GCC, Clang, MSVC)
- Make utility

### Compilation
```bash
# Build the project
make

# Build and run
make run

# Clean build artifacts
make clean

# Debug build
make debug

# Release build
make release
```

## Usage

```bash
# Run the program
./bmp_processor
```

The program will:
1. Load the sample image `1718889054_sample_640×426.bmp`
2. Create rotated versions (clockwise and counter-clockwise)
3. Apply Gaussian filter to both rotated versions
4. Save all results as new BMP files

## Output Files

- `Mandrill_rotated_clockwise.bmp` - Image rotated 90° clockwise
- `Mandrill_rotated_counter_clockwise.bmp` - Image rotated 90° counter-clockwise
- `Mandrill_filtered_clockwise.bmp` - Clockwise rotated image with Gaussian filter
- `Mandrill_filtered_counter_clockwise.bmp` - Counter-clockwise rotated image with Gaussian filter

## Technical Details

### BMP Format Support
- File header parsing (14 bytes)
- Information header parsing (40 bytes)
- Support for 24-bit and 32-bit color depth
- Proper row padding handling (4-byte alignment)

### Memory Management
- RAII (Resource Acquisition Is Initialization) design
- Automatic memory cleanup
- Memory usage tracking and reporting
- Efficient data structures

### Performance
- Optimized rotation algorithms
- Efficient Gaussian filter implementation
- Minimal memory allocations
- Real-time processing capabilities

## Algorithm Details

### Image Rotation
- **Clockwise**: `(x, y) → (height - 1 - y, x)`
- **Counter-clockwise**: `(x, y) → (y, width - 1 - x)`
- Proper handling of row padding after rotation

### Gaussian Filter
3x3 kernel with coefficients:
```
[1/16  2/16  1/16]
[2/16  4/16  2/16]
[1/16  2/16  1/16]
```

## Error Handling

The application includes comprehensive error handling for:
- File I/O operations
- Invalid BMP format
- Memory allocation failures
- Data size mismatches
- Unsupported image formats

## Performance Metrics

For the sample image (640×426, 24-bit):
- **Load time**: ~1ms
- **Rotation time**: ~1ms each direction
- **Filter time**: ~2ms each
- **Total processing time**: ~14ms
- **Memory usage**: 100.013% of data size
- **Memory efficiency**: ✓ Within 200% limit

## Testing

The program has been tested with:
- Various BMP file sizes
- Different color depths (24-bit, 32-bit)
- Memory leak detection (valgrind)
- Performance benchmarking

## License

This project is part of academic coursework and follows university guidelines.
