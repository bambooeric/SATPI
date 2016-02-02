/* RtpStreamThread.h

   Copyright (C) 2015, 2016 Marc Postema (mpostema09 -at- gmail.com)

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
   Or, point your browser to http://www.gnu.org/copyleft/gpl.html
*/
#ifndef RTP_STREAM_THREAD_H_INCLUDE
#define RTP_STREAM_THREAD_H_INCLUDE RTP_STREAM_THREAD_H_INCLUDE

#include <FwDecl.h>
#include <StreamThreadBase.h>
#include <RtcpThread.h>

FW_DECL_NS0(StreamClient);
FW_DECL_NS0(StreamInterface);
FW_DECL_NS2(decrypt, dvbapi, Client);

/// RTP Streaming thread
class RtpStreamThread :
	public StreamThreadBase {
	public:

		// =======================================================================
		//  -- Constructors and destructor ---------------------------------------
		// =======================================================================
		RtpStreamThread(StreamInterface &stream, decrypt::dvbapi::Client *decrypt);

		virtual ~RtpStreamThread();

		/// @see StreamThreadBase
		virtual bool startStreaming();

	protected:

		/// Thread function
		virtual void threadEntry();

		/// @see StreamThreadBase
		virtual void writeDataToOutputDevice(mpegts::PacketBuffer &buffer, const StreamClient &client);

		/// @see StreamThreadBase
		virtual int getStreamSocketPort(int clientID) const;

	private:

		// =======================================================================
		// -- Data members -------------------------------------------------------
		// =======================================================================
		int _socket_fd;     ///
		uint16_t _cseq;     /// RTP sequence number
		RtcpThread _rtcp;   ///

}; // class RtpStreamThread

#endif // RTP_STREAM_THREAD_H_INCLUDE
