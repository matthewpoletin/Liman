///**
// * @file ZipFile.h
// */
//
//#pragma once
//
//#include <stdio.h>
//#include <map>
//
//namespace liman {
//
//	// maps path to a zip content id
//	typedef std::map<std::string, int> ZipContentsMap;
//
//	class ZipFile {
//	public:
//		ZipFile() {
//			m_nEntries = 0;
//			m_pFile = nullptr;
//			m_pDirData = nullptr;
//		}
//
//		virtual ~ZipFile() {
//			End();
//			fclose(m_pFile);
//		}
//
//		bool Init(const std::wstring &resFileName);
//
//		void End();
//
//		int GetNumFiles() const { return m_nEntries; }
//
//		std::string GetFilename(int i) const;
//
//		int GetFileLen(int i) const;
//
//		bool ReadFile(int i, void* pBuf);
//
//		// Added to show multi-threaded decompression
//		bool ReadLargeFile(int i, void* pBuf, void(* progressCallback)(int, bool &));
//
//		int Find(const std::string &path) const;
//
//		ZipContentsMap m_ZipContentsMap;
//
//	private:
//		struct TZipDirHeader;
//		struct TZipDirFileHeader;
//		struct TZipLocalHeader;
//
//		// Zip file
//		FILE* m_pFile;
//		// Raw data buffer.
//		char* m_pDirData;
//		// Number of entries.
//		int m_nEntries;
//
//		// Pointers to the dir entries in pDirData.
//		const TZipDirFileHeader** m_papDir{};
//	};
//
//}