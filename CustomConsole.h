#pragma once

namespace BOS
{
	/// <summary>
	/// Class to read values from the console based on the data type
	/// </summary>
	class CustomConsole
	{
		/// <summary>
		/// Method to read string values from the console
		/// </summary>
		/// <returns></returns>
	public:
		static string ReadString();

		/// <summary>
		/// Method to read float values from the console
		/// </summary>
		/// <returns></returns>
		static float ReadFloat();

		/// <summary>
		/// Method to read double values from the console
		/// </summary>
		/// <returns></returns>
		static double ReadDouble();

		/// <summary>
		/// Method to read integer values from the console
		/// </summary>
		/// <returns></returns>
		static int ReadInt();

		/// <summary>
		/// Method to read char values from the console
		/// </summary>
		/// <returns></returns>
		static char ReadChar();

		static short ReadShort();
	};
}
