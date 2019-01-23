#pragma once
#include <lml_edk/config.hpp>

#include <cstddef>
#include <ostream>
#include <vector>

namespace lml_edk
{
	struct LML_EDK_EXPORT matrix_index final
	{
		std::size_t y, x;
	};

	class LML_EDK_EXPORT matrix final
	{
	public:
		matrix() noexcept = default;
		matrix(std::size_t height, std::size_t width);
		matrix(const std::vector<double>& array, std::size_t height);
		matrix(std::vector<double>&& array, std::size_t height);
		matrix(const matrix& matrix);
		matrix(matrix&& matrix) noexcept;
		~matrix() = default;

	public:
		matrix& operator=(const matrix& matrix);
		matrix& operator=(matrix&& matrix) noexcept;
		friend bool operator==(const matrix& a, const matrix& b) noexcept;
		friend bool operator!=(const matrix& a, const matrix& b) noexcept;
		double operator[](const matrix_index& index) const noexcept;
		double& operator[](const matrix_index& index) noexcept;
		friend matrix operator+(const matrix& a, const matrix& b);
		friend matrix operator-(const matrix& a, const matrix& b);
		friend matrix operator*(double c, const matrix& matrix);
		friend matrix operator*(const matrix& a, const matrix& b);
		matrix& operator+=(const matrix& other) noexcept;
		matrix& operator-=(const matrix& other) noexcept;
		matrix& operator*=(const matrix& other) noexcept;

	public:
		void clear() noexcept;
		bool empty() const noexcept;
		void swap(matrix& matrix) noexcept;
		bool zero() const noexcept;
		std::size_t height() const noexcept;
		std::size_t width() const noexcept;
		std::size_t size() const noexcept;

		matrix transpose() const;
		matrix dot(const matrix& other) const;

	private:
		std::vector<double> data_;
		std::size_t height_;
	};

	std::ostream& operator<<(std::ostream& stream, const matrix& matrix);

	matrix transpose(const matrix& matrix);
	matrix dot(const matrix& a, const matrix& b);
}