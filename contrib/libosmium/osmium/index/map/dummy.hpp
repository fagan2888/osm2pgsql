#ifndef OSMIUM_INDEX_MAP_DUMMY_HPP
#define OSMIUM_INDEX_MAP_DUMMY_HPP

/*

This file is part of Osmium (http://osmcode.org/libosmium).

Copyright 2013-2015 Jochen Topf <jochen@topf.org> and others (see README).

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <cstddef>

#include <osmium/index/index.hpp>
#include <osmium/index/map.hpp>

namespace osmium {

    namespace index {

        namespace map {

            /**
             * Pseudo map.
             * Use this class if you don't need a map, but you
             * need an object that behaves like one.
             */
            template <typename TId, typename TValue>
            class Dummy : public osmium::index::map::Map<TId, TValue> {

            public:

                Dummy() = default;

                ~Dummy() noexcept override final = default;

                void set(const TId, const TValue) override final {
                    // intentionally left blank
                }

                const TValue get(const TId id) const override final {
                    not_found_error(id);
                }

                size_t size() const override final {
                    return 0;
                }

                size_t used_memory() const override final {
                    return 0;
                }

                void clear() override final {
                }

            }; // class Dummy

        } // namespace map

    } // namespace index

} // namespace osmium

#endif // OSMIUM_INDEX_MAP_DUMMY_HPP
