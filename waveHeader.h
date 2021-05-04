//CS 202 Semester Project - PT 19

#ifndef WAVEHEADER_H
#define WAVEHEADER_H

	/**
	 * Struct containing wav file's technical data variables
	 */
typedef struct wav_header {
    // RIFF Header

    /**
	 * Riff Header variable from wav files, Contains "RIFF"
	 */
    char riff_header[4]; 
	/**
	 * Size of the wav portion of the file, which follows the first 8 bytes
	 */
    int wav_size;
	/**
	 * Contains "WAVE" from wav files
	 */
    char wave_header[4]; 

    /**
	 *Format Header - Contains "fmt " (includes trailing space)
	 */
    char fmt_header[4]; 
	/**
	 * Format chunk size for files, Should be 16 for PCM
	 */
    int fmt_chunk_size; 
	/**
	 * Audio Format data, Should be 1 for PCM. 3 for IEEE Float
	 */
    short audio_format; 
	/**
	 * Number of channels in wav files, mono or stereo
	 */
    short num_channels;
	/**
	 * Sample Rate in wav files
	 */
    int sample_rate;
	/**
	 * Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
	 */
    int byte_rate;  
	/**
	 * num_channels * Bytes Per Sample
	 */
    short sample_alignment;  
	/**
	 *  Number of bits per sample from wav files
	 */
    short bit_depth;

    // Data

	/**
	 * Contains "data"
	 */
    char data_header[4]; 
	/**
	 * Number of bytes in data. Number of samples * num_channels * sample byte size
	 */
    int data_bytes;
    // char bytes[]; // Remainder of wave file is bytes
} wav_header;

#endif

// This header copied from https://gist.github.com/Jon-Schneider/8b7c53d27a7a13346a643dac9c19d34f
/*
 * https://docs.fileformat.com/audio/wav/
 * Positions	Sample Value	Description
1 - 4	“RIFF”	Marks the file as a riff file. Characters are each 1 byte long.
5 - 8	File size (integer)	Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you’d fill this in after creation.
9 -12	“WAVE”	File Type Header. For our purposes, it always equals “WAVE”.
13-16	“fmt "	Format chunk marker. Includes trailing null
17-20	16	Length of format data as listed above
21-22	1	Type of format (1 is PCM) - 2 byte integer
23-24	2	Number of Channels - 2 byte integer
25-28	44100	Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
29-32	176400	(Sample Rate * BitsPerSample * Channels) / 8.
33-34	4	(BitsPerSample * Channels) / 8.1 - 8 bit mono2 - 8 bit stereo/16 bit mono4 - 16 bit stereo
35-36	16	Bits per sample
37-40	“data”	“data” chunk header. Marks the beginning of the data section.
41-44	File size (data)	Size of the data section.
 */ 
