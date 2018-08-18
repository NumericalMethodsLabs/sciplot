// Capim - a modern C++ plotting library powered by gnuplot
// https://github.com/allanleal/capim
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Copyright (c) 2018 Allan Leal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

// Capim includes
#include <Capim/specs/specs.hpp>
#include <Capim/util.hpp>

namespace Capim {
namespace internal {

/// The specifications for a line plot.
class linespecs : public specs
{
public:
    /// Construct a default linespecs instance.
    linespecs() {}

    /// Destroy this linespecs instance.
    virtual ~linespecs() {}

    /// Set the line style of the plot.
    auto linestyle(std::size_t value) -> linespecs& { m_linestyle = str(value); return *this; }

    /// Set the line type of the plot.
    auto linetype(std::size_t value) -> linespecs& { m_linetype = str(value); return *this; }

    /// Set the line width of the plot.
    auto linewidth(std::size_t value) -> linespecs& { m_linewidth = str(value); return *this; }

    /// Set the line color of the plot.
    auto linecolor(std::string value) -> linespecs& { m_linecolor = value; return *this; }

    /// Set the dash type of the plot.
    auto dashtype(std::size_t value) -> linespecs& { m_dashtype = str(value); return *this; }

    /// Convert this plotspecs object into a gnuplot formatted string.
    virtual auto repr() const -> std::string
    {
        std::stringstream ss;
        ss << optionvaluestr("linestyle", m_linestyle);
        ss << optionvaluestr("linetype", m_linetype);
        ss << optionvaluestr("linewidth", m_linewidth);
        ss << optionvaluestr("linecolor", m_linecolor);
        ss << optionvaluestr("dashtype", m_dashtype);
        return ss.str();
    }

private:
    /// The line style of the plot (e.g., "ls 2").
    std::string m_linestyle;

    /// The line type of the plot (e.g., "lt 3").
    std::string m_linetype;

    /// The line width of the plot (e.g., "lw 2").
    std::string m_linewidth;

    /// The line color of the plot (e.g., "lc rgb '#FF00FF'").
    std::string m_linecolor;

    /// The dash type of the plot (e.g., "dt 2").
    std::string m_dashtype;
};

} // namespace internal
} // namespace Capim
