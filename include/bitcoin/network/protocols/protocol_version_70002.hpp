/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_NETWORK_PROTOCOL_VERSION_70002_HPP
#define LIBBITCOIN_NETWORK_PROTOCOL_VERSION_70002_HPP

#include <cstddef>
#include <cstdint>
#include <memory>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/network/channel.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/protocols/protocol_timer.hpp>
#include <bitcoin/network/protocols/protocol_version_31402.hpp>
#include <bitcoin/network/settings.hpp>

namespace libbitcoin {
namespace network {

class p2p;

class BCT_API protocol_version_70002
  : public protocol_version_31402, track<protocol_version_70002>
{
public:
    typedef std::shared_ptr<protocol_version_70002> ptr;

    /**
     * Construct a version protocol instance using configured minimums.
     * @param[in]  network   The network interface.
     * @param[in]  channel   The channel on which to start the protocol.
     */
    protocol_version_70002(p2p& network, channel::ptr channel);

    /**
     * Construct a version protocol instance.
     * @param[in]  network   The network interface.
     * @param[in]  channel   The channel on which to start the protocol.
     * @param[in]  version   The required minimum peer version.
     * @param[in]  services  The required minimum peer services.
     */
    protocol_version_70002(p2p& network, channel::ptr channel,
        uint32_t minimum_version, uint64_t minimum_services);

protected:
    static message::version version_factory(
        const config::authority& authority, const settings& settings,
            uint64_t nonce, size_t height);
};

} // namespace network
} // namespace libbitcoin

#endif
