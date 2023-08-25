#pragma once

#ifndef SR_KeyboardDevice_h_
#define SR_KeyboardDevice_h_

#include <input.hpp>
#include "MappedDevice.h"

namespace SimpleRISC {
	class Computer;

	class KeyboardDevice : public MappedDevice, public SDL::InputObserver {
	public:
		static const word BUFFER_SIZE = 256;

		/// <summary> The start address of this RAM </summary>
		word address_start = 0;
		
		word keydown_interrupt = 0;
		word keyup_interrupt = 0;

		word down_head = BUFFER_SIZE - 1;
		word up_head = BUFFER_SIZE - 1;

		word down_count = 0;
		word up_count = 0;

		word keys_down[BUFFER_SIZE] = {};
		word keys_up[BUFFER_SIZE] = {};

		Computer& computer;

		KeyboardDevice(Computer& computer, word address);

		void PushKeyDown(word key);
		void PushKeyUp(word key);

		word PopKeyDown();
		word PopKeyUp();

		void Write(word address, word value);
		void WriteByte(word address, byte value);

		word Read(word address);
		byte ReadByte(word address);

		word GetAddress() const;
		word GetRange() const;

		const Device_ID GetID() const;

		void Notify(const SDL::Event& input_event);

		void Reset();
	};
}

#endif