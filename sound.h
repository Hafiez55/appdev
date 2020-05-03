// in this file we define related  contants and decleare funtion
// for handling.

// deffine sound structure (deal with .WaV FILE)
#define SAMPLERATE 16000
#define BARS 155
#define SIZE 500

typedef struct{
	char chunkID[4];	// should be always "RIFE"
	int chunkSize;
	char format[4];		// should be always "WAVE"
	char subchunk1ID[4];	// should be ALWAYS "FMT"
	int subchunk1Size;	// should be 16 for PCM
	short audioFormat;	// should be 1 for PCM
	short numChannels;	// could be 1 for mono, 2 for stereo
	int sampleRate;		// usually it's 44100, or 16000
	int byteRate;		// can be calculated
	short blockAlign;	// how many bytes in one block
	short bitsPerSample;	// could be 8 or 16
	char subchunk2ID[4];	//should be always "data"
	int subchunk2Size;	// can be calculated
}WAVheader;

// function decleration 
WAVheader readwavhdr(FILE *);
void displaywavhdr(WAVheader);
void wavdata(WAVheader, FILE *);
