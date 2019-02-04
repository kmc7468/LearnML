#pragma once

#include <lml_edk/language.hpp>

#include <string>
#include <Windows.h>

namespace lml
{
	class options final
	{
	public:
		options() noexcept = default;
		explicit options(const std::basic_string<TCHAR>& option_path);
		options(const options&) = delete;
		~options();

	public:
		options& operator=(const options&) = delete;

	public:
		void load(const std::basic_string<TCHAR>& option_path);
		void save(const std::basic_string<TCHAR>& option_path) const;

	public:
		std::basic_string<TCHAR> autosave() const;
		void autosave(const std::basic_string<TCHAR>& new_autosave);

		lml_edk::language language() const noexcept;
		void language(lml_edk::language new_language) noexcept;

		bool include_additional_data() const noexcept;
		void include_additional_data(bool new_include_additional_data) noexcept;

	private:
		std::basic_string<TCHAR> autosave_;

		lml_edk::language language_ = lml_edk::language::ko;

		bool include_additional_data_ = false;
	};
}