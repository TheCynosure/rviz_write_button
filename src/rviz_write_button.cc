/*
 * Copyright (c) 2011, Willow Garage, Inc.
 * Copyright (c) 2019, Joydeep Biswas joydeepb@cs.umass.edu
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <ros/console.h>
#include <rviz/visualization_manager.h>

#include "rviz_write_button/WriteMsg.h"
#include "rviz_write_button.h"

namespace rviz_write_button {

    WriteButton::WriteButton() {
      ros::NodeHandle n_;
      publisher_=  n_.advertise<rviz_write_button::WriteMsg>("/write_output",
                                                             10);
    }

    WriteButton::~WriteButton() {

    }

    void WriteButton::onInitialize() {

    }

    void WriteButton::activate() {
      Publish();

    }

    void WriteButton::deactivate() {
    }

    void WriteButton::Publish() {
      rviz_write_button::WriteMsg write_msg;
      write_msg.write = true;
      publisher_.publish(write_msg);
    }

} // namespace rviz_write_button

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_write_button::WriteButton, rviz::Tool)
