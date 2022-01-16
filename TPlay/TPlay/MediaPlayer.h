#pragma once

#include <string>
#include <qstring.h>
#include <list>
#include <vector>
#include <stdint.h>
#include <queue>

namespace tt {

class Output {
public:
	Output();
	~Output();
	virtual void out(uint64_t son, uint64_t ma) = 0;

//	void setCokieSize(uint64_t size);

protected:
	std::queue<uint8_t>			m_datas;
	
}; // class Output

class AudioOutput : public Output {
public:
	AudioOutput();
	~AudioOutput();

	void out(uint64_t son, uint64_t ma) override;

private:
};

class MediaPlayer
{
public:
	MediaPlayer();
	~MediaPlayer();

	void setSource(const std::string& src);
	void setAudioOutput();
	void setVideoOutput();
private:

}; // class MediaPlayer
} // namespace tt


