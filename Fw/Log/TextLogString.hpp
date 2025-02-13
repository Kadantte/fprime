#ifndef FW_TEXT_LOG_STRING_TYPE_HPP
#define FW_TEXT_LOG_STRING_TYPE_HPP

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringType.hpp>
#include <FpConfig.hpp>
#include <Fw/Cfg/SerIds.hpp>

namespace Fw {

    class TextLogString : public Fw::StringBase {
        public:

            enum {
                SERIALIZED_TYPE_ID = FW_TYPEID_LOG_STR,
                SERIALIZED_SIZE = FW_LOG_TEXT_BUFFER_SIZE + sizeof(FwBuffSizeType) // size of buffer + storage of two size words
            };

            TextLogString(const char* src);
            TextLogString(const StringBase& src);
            TextLogString(const TextLogString& src);
            TextLogString(void);
            TextLogString& operator=(const TextLogString& other);
            TextLogString& operator=(const StringBase& other);
            TextLogString& operator=(const char* other);
            ~TextLogString(void);

            const char* toChar(void) const;
            NATIVE_UINT_TYPE getCapacity(void) const ;

        private:

            char m_buf[FW_LOG_TEXT_BUFFER_SIZE];
    };

}

#endif
